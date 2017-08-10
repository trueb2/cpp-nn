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
powers = np.zeros_like(examples)
for i in range(num_examples):
    powers[i,:] = examples[i,:]
    for j in range(num_features):
        powers[i,j] = powers[i,j]**(j+1)

sums = np.dot(powers, weights)
mid = sum([.5**(i+1) for i in range(num_features)])
labels = (sums > mid).astype(bool)

# Save the examples and labels
np.savetxt("../data_tmp/poly_examples_%s_%s" % (num_examples, num_features), examples, delimiter=',')
np.savetxt("../data_tmp/poly_labels_%s_%s" % (num_examples, num_features), labels.astype(int), delimiter=',', fmt="%d")

if(num_features == 2):
    labels.shape = (num_examples,)
    pos_examples = examples[labels]
    neg_examples = examples[~labels]
    fig = plt.figure()
    plt.scatter(pos_examples[:,0], pos_examples[:,1])
    plt.scatter(neg_examples[:,0], neg_examples[:,1])
    fig.savefig("../data_tmp/poly_plot_%s_%s.png" % (num_examples, num_features))
