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
	square_size = 0
	rect = 0
	board_center = 0
	board_size = 0
	board_size_pervius = 0
	clicked = False
	selected_piece = 0
	square_previus = 0
	selected = False
	lista_img_scale = []
	moves = 0

	def __init__(self, screen):
		self.screen = screen
		self.rect = pygame.Rect(self.board_size, self.board_size, self.board_size, self.board_size)

	def init_squares(self, color_cliked):
		colors = [Color(93,50,49), Color(121,72,57)]
		move = Color(158, 32, 16)
		take = Color(232, 225, 9)
		selected = Color(6, 68, 184)
		color_set = True

		y = 0
		while y < 8:
			x = 0
			lista = []
			while x < 8:
				color = (colors[0], colors[1])[color_set]
				lista.append(Square(self.screen, self.square_size, y, x, (color, take, move, selected)))
				color_set = not color_set
				x += 1
			self.squares.append(lista)
			color_set = not color_set
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
		y = 0
		while y < 8:
			x = 0
			while x < 8:
				self.squares[y][x].draw()
				x += 1
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
	def clear_moves(self):
		for square in self.moves:
			for squarex in square:
				self.squares[squarex[0]][squarex[1]].change_state("normal")
		return

	def check_pos(self):
		point = pygame.mouse.get_pos()

		if self.selected:
			for y, sqr in enumerate(self.squares):
				for x, item in enumerate(sqr):
					selected = item.is_collide(point)
					if not selected:
						continue
					
					self.clear_moves()
					self.square_previus.change_state("normal")

					if self.pieces_pos[y][x] == self.selected_piece:
						self.selected = False
						self.selected_piece = 0
						return

					if (y,x) in self.moves[0]:
						self.selected_piece.move(item.pos, self, self.pieces_pos[item.pos[0]][item.pos[1]])
					if (y,x) in self.moves[1]:
						self.selected_piece.move(item.pos, self, self.pieces_pos[item.pos[0]][item.pos[1]])

					self.selected_piece = 0
					self.selected = False
					return		
			return

		for y, sqr in enumerate(self.squares):
			for x, item in enumerate(sqr):
				if self.pieces_pos[y][x] == '':
					continue
				
				self.selected = item.is_collide(point)
				if self.selected:
					self.square_previus = item
					item.change_state("selected")
					self.selected_piece = self.pieces_pos[y][x]
					print(f"x = {self.selected_piece.x} | y = {self.selected_piece.y}")

					self.moves = self.selected_piece.piece_obj.moves(self.pieces_pos, (self.selected_piece.y, self.selected_piece.x), self.selected_piece.onwer)
					for square in self.moves[0]:
						self.squares[square[0]][square[1]].change_state("move")
					for square in self.moves[1]:
						self.squares[square[0]][square[1]].change_state("take")
					return
					

	def check_click(self, event):
		click = pygame.mouse.get_pressed()[0]
		if click and not self.clicked:
			self.clicked = True
			self.check_pos()

		if not pygame.mouse.get_pressed()[0]:
			self.clicked = False

	def is_check():
		pass
	def is_mate():
		pass
	def is_possible_castling():
		pass