PROGRAM	:= example
exe: $(PROGRAM).class
	java $(PROGRAM)
$(PROGRAM).class: example.jasm
	../javaa/javaa example.jasm
example.jasm: $(PROGRAM).scala
	../parser < $(PROGRAM).scala
clean:
	rm *.class *.jasm
