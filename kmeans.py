import numpy as np

def kmeans(data, k, iter):
    m, n = len(data), len(data[0])
    data = np.array(data)
    clusters = np.array([data[np.random.choice(m)] for _ in range(k)])
    clusters_labels = np.empty(m, np.int)
    while iter:
        data_ = np.reshape(data.repeat(k, axis=0), [m, k, n])
        distance = np.sqrt(np.sum(np.square(data_ - clusters), axis=-1))
        clusters_labels_new = np.argmin(distance, axis=-1)
        if(clusters_labels == clusters_labels_new):
            return clusters_labels_new
        else:
            for i in range(k):
                temp = data[i == clusters_labels_new]
                clusters[i] = np.mean(temp, axis=0)
            clusters_labels = clusters_labels_new
            iter -= 1
    return clusters_labels