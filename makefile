.PHONY: install clean check test

clock: clock.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o clock clock.c $(LDFLAGS)

install: clock
	install clock $(DESTDIR)$(prefix)/bin/

clean:
	$(RM) clock

check: clock
test: clock
