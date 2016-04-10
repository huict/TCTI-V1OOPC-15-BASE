.PHONY: clean All

All:
	@echo "----------Building project:[ 08-03-vector-public -  ]----------"
	@cd "08-03-vector-public" && "$(MAKE)" -f  "08-03-vector-public.mk"
clean:
	@echo "----------Cleaning project:[ 08-03-vector-public -  ]----------"
	@cd "08-03-vector-public" && "$(MAKE)" -f  "08-03-vector-public.mk" clean
