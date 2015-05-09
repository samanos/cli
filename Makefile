cflags=-Wall -Os -std=gnu99 -g

name=cli
srcs=src/cli.c
objs=$(subst .c,.o,$(srcs))
lsts=$(subst .c,.lst,$(srcs))

# libusb
libs+=-lusb-1.0

cflags+=-I vendor/protocol/src

ui=vendor/usb-interface/src
cflags+=-I $(ui)
srcs+= \
	$(ui)/usb_interface.c

$(name): $(objs)
	gcc -o $@ $(objs) $(libs)

clean:
	rm -f $(objs) $(name)

%.o: %.c
	gcc -c $(cflags) -o $@ $< $(libs)
