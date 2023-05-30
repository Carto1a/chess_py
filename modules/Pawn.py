import pygame
from pygame.locals import *

class Pawn:
	fist_move = True
	en_passantble = False

	def __init__(self):
		pass

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
			self.fist_move = False
		else:
			v = (-1, 1)[onwer == 'b']

		b = y + v

		if y == limit:
			return [moves, takes]

		# if x > 0:
		# 	l1 = pieces_pos[y][x-1]
		# if x < 7:
		# 	l2 = pieces_pos[y][x+1]

		# if x < 6 and l2 != "" and l2.piece_type == 'p' and l2.onwer != onwer and l1.piece_obj.en_passantble:
		# 	takes.append((y+q, x+1))
		# if x > 1 and l1 != "" and l1.piece_type == 'p' and l1.onwer != onwer and l1.piece_obj.en_passantble:
		# 	takes.append((y+q, x-1))
		# if x < 6 and pieces_pos[y][x+1] != "" and pieces_pos[y+q][x+1].onwer != onwer:
		# 	takes.append((y+q, x+1))
		# if x > 1 and pieces_pos[y+q][x-1] != "" and pieces_pos[y+q][x-1].onwer != onwer:
		# 	takes.append((y+q, x-1))

		while y != b:
			y += q
			if y > 7 or y < 0:
				print("passou")
				return [moves, takes]

			if pieces_pos[y][x] != '':
				return [moves, takes]

			moves.append((y, x))

		return [moves, takes]

