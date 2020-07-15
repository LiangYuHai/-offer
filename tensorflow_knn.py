import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import numpy as np
mnist = input_data.read_data_sets('MNIST_data', one_hot=False)
K = 100
train_set = mnist.train.images
train_labels = mnist.train.labels
test_set = mnist.test.images
test_labels = mnist.test.labels
train_num = 10000
test_num = 100

x = tf.placeholder(tf.float32, [None, 784])
x_test = tf.placeholder(tf.float32, [784])

knn = tf.reduce_sum(tf.square(x - x_test), reduction_indices=1)

with tf.Session() as sess:
    a = []
    for i in range(test_num):
        result = sess.run(knn, feed_dict={x: train_set[:], x_test: test_set[i]})
        min_distance_indexs = result.argsort()[:K]
        knn_labels = np.array([train_labels[i] for i in min_distance_indexs])
        prediction = np.argmax(np.bincount(knn_labels))
        #print('prediction : ', prediction, 'fact : ', test_labels[i])
        a.append(prediction == test_labels[i])
    accuracy = tf.reduce_mean(tf.cast(a, dtype=tf.float32))
    print('accuracy:', sess.run(accuracy))
