import pygame
from pygame.locals import *

class Square:
	clicked      = 0
	color        = 0
	color_cliked = 0
	pos          = 0
	size         = 0
	sqt          = 0
	screen       = 0
	selected     = False 

	def __init__(self, square_size, color, x, y):
		self.pos = (x, y)
		self.size = square_size
		self.color_cliked = color
		self.sqt = pygame.Rect(self.size, self.size, self.size, self.size)

	def __str__(self):
		return self.sqt

	def update(self, board_pos, square_size):
		self.sqt.update(board_pos[0] + square_size * self.pos[1], board_pos[1] + square_size * self.pos[0], square_size, square_size)

	def draw(self, screen, color):
		self.color = color
		self.screen = screen
		if self.clicked:
			pygame.draw.rect(self.screen, self.color_cliked, self.sqt)
			return

		pygame.draw.rect(screen, color, self.sqt)

	def click(self, point):
		collide = self.sqt.collidepoint(point)
		if collide:
			self.clicked = not self.clicked
			color = (self.color_cliked, self.color)[self.clicked]
			self.draw(self.screen, color)

			self.selected = not self.selected

			return self.selected
			
		return False
