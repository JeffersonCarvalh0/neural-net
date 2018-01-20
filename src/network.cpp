# include "network.h"
# include <random>

using namespace std;
using namespace Eigen;

Network::Network(const vector<size_t> &sizes) {
    num_layers = sizes.size();
    this->sizes = sizes;

    // Setting the random gaussian distribution
    default_random_engine generator;
    normal_distribution<double> biasesDist(0, 1);
    normal_distribution<double> weightsDist(0, 1);

    // Set the biases for each layer in the network
    biases = vector<VectorXf>(num_layers - 1);
    for (size_t i = 0; i < num_layers - 1; ++i) {
        biases[i] = VectorXf(sizes[i + 1]);
        for (size_t j = 0; j < sizes[i + 1]; ++j)
            biases[i][j] = biasesDist(generator);
    }

    // Set matrixes of weights for the neurons
    weights = vector<MatrixXf>(num_layers - 1);
    for (size_t i = 0; i < num_layers; ++i) { // Selects the layer
        if (i + 1 < num_layers) {
            weights[i] = MatrixXf(sizes[i + 1], sizes[i]);
            for (size_t j = 0; j < sizes[i + 1]; ++j) { // Right layer neurons
                for (size_t k = 0; k < sizes[i]; ++k) { // Left layer neurons
                    weights[i](j, k) = weightsDist(generator);
                }
            }
        }
    }
}

VectorXf Network::sigmoid(VectorXf &z) {
    // Applies the sigmoid function on a layer
    z = 1.0 / (1.0 + (z * -1).array().exp());
    return z;
}

// VectorXf Network::feedforward(VectorXf input) {
//     for (size_t i = 0; i < weights.size(); ++i)
//         input = sigmoid((weights[i] * input) + biases[i]);
//     return input;
// }
