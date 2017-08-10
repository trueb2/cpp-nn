# Create Random Data
import numpy as np
import matplotlib.pyplot as plt

# Generate random examples and label weights
num_examples = 1000
num_features = 2
examples = np.random.rand(num_examples, num_features)
weights = np.random.rand(num_features, 1)
bias = np.random.rand()

# Compute linear combination (label) of examples on random weight
sums = np.dot(examples, weights)
labels = (sums > .25 * num_features).astype(bool)

# Save the examples and labels
np.savetxt("../data_tmp/lin_examples_%s_%s" % (num_examples, num_features), examples, delimiter=',')
np.savetxt("../data_tmp/lin_labels_%s_%s" % (num_examples, num_features), labels.astype(int), delimiter=',', fmt="%d")

if(num_features == 2):
    labels.shape = (num_examples,)
    pos_examples = examples[labels]
    neg_examples = examples[~labels]
    fig = plt.figure()
    plt.scatter(pos_examples[:,0], pos_examples[:,1])
    plt.scatter(neg_examples[:,0], neg_examples[:,1])
    fig.savefig("../data_tmp/lin_plot_%s_%s.png" % (num_examples, num_features))
