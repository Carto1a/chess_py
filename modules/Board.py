import pygame
from pygame.locals import *
from modules.Square import Square
from modules.Pieces import Pieces

class Board:
	# pieces = [['br','bn','bb','bq','bk','bb','bn','br'],
# 					['bp','bp','bp','bp','bp','bp','bp','bp'],
# 					['','','','','','','',''],
# 					['','','','','','','',''],
# 					['','','','','','','',''],
# 					['','','','','','','',''],
# 					['wp','wp','wp','wp','wp','wp','wp','wp'],
# 					['wr','wn','wb','wq','wk','wb','wn','wr']]
	pieces_pos = [['bp','bp','bp','bp','bp','bp','bp','bp'],
								['bp','bp','bp','bp','bp','bp','bp','bp'],
								['',   '', '',  '',  '',  '',  '',  ''  ],
								['',   '', '',  '',  '',  '',  '',  ''  ],
								['',   '', '',  '',  '',  '',  '',  ''  ],
								['',   '', '',  '',  '',  '',  '',  ''  ],
								['wp','wp','wp','wp','wp','wp','wp','wp'],
								['wp','wp','wp','wp','wp','wp','wp','wp']
				     	 ]
	pieces = []
	squares = []
	board_size = 0
	color_cliked = 0
	square_size = 0
	rect = 0
	board_center = 0
	board_size = 0
	board_size_pervius = 0
	clicked = False
	selected_piece = 0
	selected = False
	lista_img_scale = []

	def __init__(self, screen):
		self.screen = screen
		self.rect = pygame.Rect(self.board_size, self.board_size, self.board_size, self.board_size)

	def init_squares(self, color_cliked):
		self.color_cliked = color_cliked

		y = 0
		while y < 8:
			x = 0
			lista = []
			while x < 8:
				lista.append(Square(self.square_size, Color(44, 59, 120, 10), y, x))
				x += 1
			self.squares.append(lista)
			y += 1

	def init_pieces(self):
		for indexy, itemy in enumerate(self.pieces_pos):
			for indexx, item in enumerate(itemy):
				if item == '':
					continue
				
				if item[1] == "p":
					self.pieces_pos[indexy][indexx] = Pieces(item[0], "pawn", indexy, indexx, self.screen)

				self.pieces.append(self.pieces_pos[indexy][indexx])

	def update_size_pos(self, board_center, board_size):
		self.board_center = board_center
		self.board_size = board_size
		self.rect.update(board_center[0], board_center[1], board_size, board_size)

	def update_squares(self):
		square_size = self.board_size / 8

		y = 0
		while y < 8:
			x = 0
			while x < 8:
				self.squares[y][x].update(self.board_center, square_size)
				x += 1
			y += 1

	def draw_squares(self):

		colors = [Color(93,50,49), Color(121,72,57)]
		color_set = True

		y = 0
		while y < 8:
			x = 0
			while x < 8:
				color = (colors[0], colors[1])[color_set]
				self.squares[y][x].draw(self.screen, color)
				color_set = not color_set
				x += 1
			color_set = not color_set
			y += 1

	def draw_pieces(self, reload_images=None):
		pos_cal = (self.rect.width / 8)
		if self.board_size != self.board_size_pervius:
			self.lista_img_scale = reload_images(self.board_size)
			self.board_size_pervius = self.board_size
			for item in self.pieces:
				if item == '':
					continue
				if item.onwer == "b":
					if item.piece_type == "p":
						item.update(pos_cal, self.rect, self.lista_img_scale[3])
				else:
					if item.piece_type == "p":
						item.update(pos_cal, self.rect, self.lista_img_scale[9])
				
				item.draw()
				
		else:
			for item in self.pieces:
				if item == '':
					continue
				item.update(pos_cal, self.rect)
				item.draw()

	# proibir o toque quanto ja tiver um selecionado
	# verificar se o movimento é valido
	# 
	def check_pos(self):
		point = pygame.mouse.get_pos()
		if self.selected:
			for y, sqr in enumerate(self.squares):
				for x, item in enumerate(sqr):
					selected = item.click(point)
					if selected:
						self.selected_piece.move(item.pos, self)
						self.selected = False
						return
					
			return

		for y, sqr in enumerate(self.squares):
			for x, item in enumerate(sqr):
				if self.pieces_pos[y][x] == '':
					continue
				
				self.selected = item.click(point)
				if self.selected:
					self.selected_piece = self.pieces_pos[y][x]
					return

	def check_click(self, event):
		click = pygame.mouse.get_pressed()[0]
		if click and not self.clicked:
			self.clicked = True
			self.check_pos()

		if not pygame.mouse.get_pressed()[0]:
			self.clicked = False

