# include "network.h"
# include <iostream>

using namespace std;
using namespace Eigen;

int main() {
    vector<size_t> sizes = {2, 3, 1};
    Network net(sizes);
    VectorXf input(2); input << 1, 2;

    input << 1, 2;

    for (size_t i = 0; i < net.biases.size(); ++i) {
        cout << "Biases from the layer " << i + 1 << '\n';
        cout << net.biases[i] << "\n\n";
    }

    for (size_t i = 0; i < net.weights.size(); ++i) {
        cout << "Weights between the layers " << i + 1 << " and " << i + 2 << '\n';
        cout << net.weights[i] << "\n\n";
    }

    // cout << input << endl;
    // net.sigmoid(input);
    // cout << input << endl;

    cout << "Feedforward results:\n";
    cout << net.feedforward(input) << endl;

    return 0;
}
