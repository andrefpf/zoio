import numpy as np 
import matplotlib.pyplot as plt
from PIL import Image


def plot_matrix(matrix):
    plt.imshow(matrix, vmin=0, vmax=255, cmap='gray')
    plt.show()

def load_img(path):
    img = Image.open(path)
    frame = np.asarray(img)
    r = frame[:,:,0]
    g = frame[:,:,1]
    b = frame[:,:,2]
    return r,g,b
    
def load_matrix(path):
    with open(path, 'r') as file:
        string = file.read()

    ints = [int(i) for i in string.split()]
    w, h = ints[0:2]

    matrix = np.array(ints[2:])
    matrix.resize(h,w)
    return matrix


def save_matrix(path, matrix):
    string = ''
    h,w = matrix.shape

    string += f'{w} {h} \n'

    for i in range(h):
        for j in range(w):
            string += f'{matrix[i,j]} '
        string += '\n'

    with open(path, 'w') as file:
        file.write(string)

if __name__ == "__main__":
    # r,g,b = load_img('tmp/0.jpg')
    m = load_matrix('tmp/shrek_dwt.txt')
    # save_matrix('tmp/shrek.txt', r)
    plot_matrix(m)
    pass