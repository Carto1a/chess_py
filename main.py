import pygame
import array
import math
import cairo
import pygame
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

lista_img.append(pygame.image.load("./assets/pieces/b_bishop.png"))  # 0
lista_img.append(pygame.image.load("./assets/pieces/b_king.png"))    # 1
lista_img.append(pygame.image.load("./assets/pieces/b_knight.png"))  # 2
lista_img.append(pygame.image.load("./assets/pieces/b_pawn.png"))    # 3
lista_img.append(pygame.image.load("./assets/pieces/b_queen.png"))   # 4
lista_img.append(pygame.image.load("./assets/pieces/b_rook.png"))    # 5
lista_img.append(pygame.image.load("./assets/pieces/w_bishop.png"))  # 6
lista_img.append(pygame.image.load("./assets/pieces/w_king.png"))    # 7
lista_img.append(pygame.image.load("./assets/pieces/w_knight.png"))  # 8
lista_img.append(pygame.image.load("./assets/pieces/w_pawn.png"))    # 9
lista_img.append(pygame.image.load("./assets/pieces/w_queen.png"))   # 10
lista_img.append(pygame.image.load("./assets/pieces/w_rook.png"))    # 11

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