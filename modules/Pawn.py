import pygame
from pygame.locals import *

class Pawn:
	def __init__(self):
		pass

	def draw(self):
		screen.blit(teste, (board.x, board.y))

	def update(self):
		pygame.transform.smoothscale(teste, (board_size / 8, board_size / 8))
		screen.blit(teste, (board.x, board.y))

