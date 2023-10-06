.PHONY: clean All

All:
	@echo "----------Building project:[ Ejemplo13 - Debug ]----------"
	@cd "Ejemplo13" && "$(MAKE)" -f  "Ejemplo13.mk"
clean:
	@echo "----------Cleaning project:[ Ejemplo13 - Debug ]----------"
	@cd "Ejemplo13" && "$(MAKE)" -f  "Ejemplo13.mk" clean
