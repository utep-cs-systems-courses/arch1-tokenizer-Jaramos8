
OBJS = uimain.o tokenizer.o history.o

all: token

token: $(OBJS)
	cc -o token $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o token

run: token
	./token
