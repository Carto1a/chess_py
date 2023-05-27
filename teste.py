from Square import Square


newClass = Square(5)
val = newClass.getTeste()

print(val)

		# elif event.type == MOUSEBUTTONDOWN:
		# 	if event.button == 1:
		# 		print(event.pos)
		# 		click_mouse(squares)
		# WindowResized
		# elif event.type == pygame.VIDEORESIZE:
		# 	width, height = event.size
		# 	if width < 629:
		# 		width = 630
		# 	if height < 359:
		# 		height = 360
		# 		screen.
				# pygame.display.set_mode((width,height), HWSURFACE|DOUBLEBUF|RESIZABLE)

# player_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)

	# print(f"{board.width} - {board.height}")



WIDTH = 512
HEIGHT = 512

data = array.array('c', chr(0) * WIDTH * HEIGHT * 4)
surface = cairo.ImageSurface.create_for_data(
    data, cairo.FORMAT_ARGB32, WIDTH, HEIGHT, WIDTH * 4)

pygame.init()
window = pygame.display.set_mode((WIDTH, HEIGHT))
svg = rsvg.Handle(file="test.svg")
ctx = cairo.Context(surface)
svg.render_cairo(ctx)

screen = pygame.display.get_surface()
image = pygame.image.frombuffer(data.tostring(), (WIDTH, HEIGHT),"ARGB")
screen.blit(image, (0, 0)) 
pygame.display.flip() 