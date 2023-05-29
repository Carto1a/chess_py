import os
import pygame
import array
import math
import cairo
import pygame
import numpy
from pygame.locals import *
from modules.Board import Board

pygame.init()

lista_img = []

running = True
board_size = 0
board_size_pervius = 0
line_size = 0
line_size_x = 25
selected = False
screen_size_previus = (0,0)
mouse_button_down = 0
theme_dir = ''
currenct_theme = '0'

if currenct_theme in os.listdir('assets/pieces'):
	for item in numpy.sort(os.listdir(f'assets/pieces/{currenct_theme}')):
		lista_img.append(pygame.image.load(f"assets/pieces/{currenct_theme}/{item}"))
	
else:
	print("esse tema não exite")

# b_bishop   0
# b_king     1
# b_knight   2 
# b_pawn     3
# b_queen    4
# b_rook     5
# w_bishop   6
# w_king     7
# w_knight   8
# w_pawn     9
# w_queen    10
# w_rook     11

screen  = pygame.display.set_mode((640, 360), HWSURFACE|DOUBLEBUF|RESIZABLE)
clock   = pygame.time.Clock()
board   = Board(screen)
line    = pygame.Rect(line_size, line_size, line_size, line_size)

def reload_images(board_size):
	lista = []
	size_cal = board_size / 8

	for item in lista_img:
		lista.append(pygame.transform.smoothscale(item, (size_cal, size_cal)))

	return lista

board.init_squares(Color(44, 59, 120, 10))
board.init_pieces()

while running:
	for event in pygame.event.get():
		# print(pygame.event.event_name(event.type))
		if event.type == QUIT:
			running = False
		if event.type == MOUSEBUTTONDOWN:
			mouse_button_down = event
			# print(mouse_button_down)

	if screen_size_previus != (screen.get_width(), screen.get_height()):
		screen_size_previus = (screen.get_width(), screen.get_height())
		screen_size = (screen.get_width() / 2, screen.get_height() / 2)

		if screen_size[0] > screen_size[1]:
			# largura é maior
			board_size = screen.get_height() - ((screen_size[1] + screen_size[0]) / 28 )
			line_size = screen.get_height()
				
		else:
			# altura é maior
			board_size = screen.get_width() - ((screen_size[1] + screen_size[0]) / 28 )
			line_size = screen.get_width()

		board_center = ((screen_size[0] - board_size / 2), (screen_size[1] - board_size / 2))
		line_center = (screen_size[0] - line_size / 2, screen_size[1] - line_size / 2)

		line.update(line_center[0], line_center[1], line_size, line_size)
		board.update_size_pos(board_center, board_size)
		board.update_squares()

	screen.fill(Color(56,56,56))

	pygame.draw.rect(screen, "black", line)
	pygame.draw.rect(screen, "black", board.rect)

	board.draw_squares()
	board.check_click(mouse_button_down)
	board.draw_pieces(reload_images)

	mouse_button_down = 0

	pygame.display.flip()

	clock.tick(120)

pygame.quit()