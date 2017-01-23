
CFLAGS =  -c -g -fPIC -DLSB_FIRST -DEMU_COMPILE -DEMU_LITTLE_ENDIAN -I. -Ispu/ $(OPTFLAGS)

OBJS = eng_psf.o eng_psf2.o psx_hw.o psx.o r3000dis.o spu/spu.o spu/spucore.o

all: libaopsf.a

libaopsf.a : $(OBJS)
	$(AR) rcs $@ $^

libaopsf.so: $(OBJS)
	$(CC) $^ -shared -Wl,-soname -Wl,$@.2 -o $@.2.0

.c.o:
	$(CC) $(CFLAGS) -o $@ $*.c

rsp_lle/rsp.o: rsp_lle/rsp.c
	$(CC) $(CFLAGS) -o $@ $^

test/bench.o: test/bench.c
	$(CC) $(CFLAGS) -I../psflib -o $@ $^

test/dumpresampled.o: test/dumpresampled.c
	$(CC) $(CFLAGS) -I../psflib -o $@ $^

clean:
	rm -f $(OBJS) libaopsf.a libaopsf.so*
