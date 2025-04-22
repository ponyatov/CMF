.PHONY: format
format: tmp/format_cpp

tmp/format_cpp: $(C) $(H) $(R) $(M)
	$(CF) $? && touch $@

tmp/format_py: $(P)
	$(PEP) $? && touch $@

tmp/format_js: $(J)
	$(CF) $? && touch $@
