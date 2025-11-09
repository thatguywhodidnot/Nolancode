import pygame
from pydub import *



sound = AudioSegment.from_wav('Bruh01.wav')
cut = sound[500:]

cut.export("Bruh02.wav", format="wav")

pygame.mixer.init()
test = pygame.mixer.Sound('Bruh02.wav')
test.play()