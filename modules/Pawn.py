import pygame
from pygame.locals import *
from modules.Pieces import Pieces

class Pawn(Pieces):
	fist_move = True
	en_passantble = True
	can_en_passantble = False

	def move(self, pos, board):
		dead_piece = board.pieces_pos[pos[0]][pos[1]]
		if dead_piece == self:
			return

		# nao to com c

		for i, item in enumerate(board.pieces):
			if item == dead_piece:
				dead_piece = ''
				board.pieces[i] = ''

		board.pieces_pos[self.y][self.x] = ''
		board.pieces_pos[pos[0]][pos[1]] = self
		self.x = pos[1]
		self.y = pos[0]

		self.fist_move = False

		board.draw_pieces()

	def moves(self, pieces_pos, pos, onwer):
		moves = []
		takes = []
		y = pos[0]
		x = pos[1]
		q = 0
		limit = 0

		q = (-1, 1)[onwer == 'b']
		limit = (0, 7)[onwer == 'b']

		if self.fist_move:
			v = (-2, 2)[onwer == 'b']
		else:
			v = (-1, 1)[onwer == 'b']

		b = y + v

		if y == limit:
			return [moves, takes]

		if x > 0:
			l1 = pieces_pos[y][x-1]
		if x < 7:
			l2 = pieces_pos[y][x+1]

		if x < 6 and l2 != "" and isinstance(l2, Pawn) == True and l2.onwer != onwer and l2.en_passantble:
			takes.append((y+q, x+1))
			can_en_passantble = True
		if x > 1 and l1 != "" and isinstance(l1, Pawn) == True and l1.onwer != onwer and l1.en_passantble:
			takes.append((y+q, x-1))
			can_en_passantble = True
		if x < 6 and pieces_pos[y+q][x+1] != "" and pieces_pos[y+q][x+1].onwer != onwer:
			takes.append((y+q, x+1))
		if x > 1 and pieces_pos[y+q][x-1] != "" and pieces_pos[y+q][x-1].onwer != onwer:
			takes.append((y+q, x-1))

		while y != b:
			y += q
			if y > 7 or y < 0:
				return [moves, takes]

			if pieces_pos[y][x] != '':
				return [moves, takes]

			moves.append((y, x))

		return [moves, takes]
