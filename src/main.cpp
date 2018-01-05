# include "network.h"
# include <iostream>
# include <vector>

using namespace std;

int main() {
    vector<size_t> sizes = {2, 3, 1};
    Network net(sizes);

    for (size_t i = 0; i < net.biases.size(); ++i) {
        cout << "Biases from the layer " << i + 1 << '\n';
        cout << net.biases[i] << "\n\n";
    }

    for (size_t i = 0; i < net.weights.size(); ++i) {
        cout << "Weights between the layers " << i + 1 << " and " << i + 2 << '\n';
        cout << net.weights[i] << "\n\n";
    }

    return 0;
}
