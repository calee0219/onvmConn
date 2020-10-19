.PHONY: all


all: main.go
	CGO_LDFLAGS_ALLOW="-Wl,(--whole-archive|--no-whole-archive)" go build -gcflags=all="-N -l" ./main.go
	echo "app name: $(shell basename $(CURDIR))"
	mkdir -p build/app
	cp main build/app/$(shell basename $(CURDIR))
