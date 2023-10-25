import cv2
import numpy as np
from matplotlib import pyplot as plt

### DEFINICAO DE FUNCOES ###

def show_img(img):
  # fig = plt.gcf()               # CONFIG PARA AUMENTAR TAMANHO IMAGEM NA TELA
  # fig.set_size_inches(18, 6)    # CONFIG PARA AUMENTAR TAMANHO IMAGEM NA TELA
  # plt.axis('off')               # CONFIG PARA TIRAR A MARCACAO DOS EIXOS DA IMAGEM

  plt.imshow(img, cmap = 'gray')
  plt.show()

def limiarizacao_binary(img, limiar = 120):
  _, thresh = cv2.threshold(img, limiar, 255, cv2.THRESH_BINARY)

  return thresh

def limiarizacao_binary_inv(img, limiar = 120):
  _, thresh = cv2.threshold(img, limiar, 255, cv2.THRESH_BINARY_INV)

  return thresh

def limiarizacao_trunc(img, limiar = 120):
  _, thresh = cv2.threshold(img, limiar, 255, cv2.THRESH_TRUNC)

  return thresh

def limiarizacao_tozero(img, limiar = 120):
  _, thresh = cv2.threshold(img, limiar, 255, cv2.THRESH_TOZERO)

  return thresh

def limiarizacao_tozero_inv(img, limiar = 120):
  _, thresh = cv2.threshold(img, limiar, 255, cv2.THRESH_TOZERO_INV)

  return thresh

def show_tipos_limiarizacao(img, limiar = 127):
  binary = limiarizacao_binary(img_GRAY, limiar)
  binary_inv = limiarizacao_binary_inv(img_GRAY, limiar)
  trunc = limiarizacao_trunc(img_GRAY, limiar)
  tozero = limiarizacao_tozero(img_GRAY, limiar)
  tozero_inv = limiarizacao_tozero_inv(img_GRAY, limiar)

  titulos = ["Imagem original", "Binary", "Binary Inv", "Trunc", "To Zero", "To Zero Inv"]
  imgs = [img, binary, binary_inv, trunc, tozero, tozero_inv]

  fig = plt.gcf()
  fig.set_size_inches(18, 12)

  for i in range(6):
    plt.subplot(2, 3, i + 1)
    plt.imshow(imgs[i], cmap = 'gray')
    plt.title(titulos[i])
    plt.xticks([])
    plt.yticks([])
  
  plt.show()


### INICIO DA EXECUCAO ###


path_img = 'exemplos/dados/imagens/paisagem01.jpg'

img_BGR = cv2.imread(path_img)
img_RGB = cv2.cvtColor(img_BGR, cv2.COLOR_BGR2RGB)
img_GRAY = cv2.cvtColor(img_RGB, cv2.COLOR_RGB2GRAY)

limiar = 140

show_tipos_limiarizacao(img_GRAY, limiar)
