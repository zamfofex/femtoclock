.PHONY: install clean check test

clock: clock.c
	$(CC) -o clock clock.c

install: clock
	install clock $(DESTDIR)/bin/

clean:
	$(RM) clock

check: clock
test: clock
