.PHONY: serve
serve:
	docker run -it -v $(PWD):/repo -p 9000:9000 store/gitpitch/desktop:pro
