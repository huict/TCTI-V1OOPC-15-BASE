.PHONY: clean All

All:
	@echo "----------Building project:[ 21-05-mirror -  ]----------"
	@cd "21-05-mirror" && "$(MAKE)" -f  "21-05-mirror.mk"
clean:
	@echo "----------Cleaning project:[ 21-05-mirror -  ]----------"
	@cd "21-05-mirror" && "$(MAKE)" -f  "21-05-mirror.mk" clean
