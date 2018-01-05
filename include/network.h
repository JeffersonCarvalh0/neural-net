# ifndef NETWORK_H
# define NETWORK_H

# include <vector>
# include <Eigen/Dense>

class Network {
public:
    std::size_t num_layers;
    std::vector<size_t> sizes;
    std::vector<Eigen::VectorXf> biases;
    std::vector<Eigen::MatrixXf> weights;

public:
    Network(const std::vector<size_t> &sizes);
};

# endif /* end of include guard: NETWORK_H */
