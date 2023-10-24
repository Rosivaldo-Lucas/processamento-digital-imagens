import cv2
import numpy as np
from matplotlib import pyplot as plt

path_img = 'exemplos/dados/imagens/paisagem01.jpg'

img_BGR = cv2.imread(path_img)
img_RGB = cv2.cvtColor(img_BGR, cv2.COLOR_BGR2RGB)
img_GRAY = cv2.cvtColor(img_RGB, cv2.COLOR_RGB2GRAY)

### LIMIARIZAÇÃO - THRESH BINARY

limiar = 140

val_limiar, thresh = cv2.threshold(img_GRAY, limiar, 255, cv2.THRESH_BINARY)

fig = plt.gcf()
fig.set_size_inches(18, 6)

plt.imshow(thresh, cmap = 'gray')
plt.axis('off')
plt.show()

# cv2.imwrite('resultado.jpg', thresh)
