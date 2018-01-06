APP = adau1761init

# Add any other object files to this list below
APP_OBJS = adau1761init.o

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(APP_OBJS) $(LDLIBS)

