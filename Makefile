FLAGS = -pedantic-errors -std=c++11
OBJS = edit_load_profile.o generate_extract_word.o generate_hint_validate.o instructions_intro_leaderboard.o display_word.o WordMind.o

edit_load_profile.o: edit_load_profile.cpp edit_load_profile.h
	g++ $(FLAGS) -c edit_load_profile.cpp

generate_extract_word.o: generate_extract_word.cpp generate_extract_word.h
	g++ $(FLAGS) -c generate_extract_word.cpp

generate_hint_validate.o: generate_hint_validate.cpp generate_hint_validate.h
	g++ $(FLAGS) -c generate_hint_validate.cpp

instructions_intro_leaderboard.o: instructions_intro_leaderboard.cpp instructions_intro_leaderboard.h
	g++ $(FLAGS) -c instructions_intro_leaderboard.cpp

display_word.o: display_word.cpp display_word.h
	g++ $(FLAGS) -c display_word.cpp

WordMind.o: WordMind.cpp
	g++ $(FLAGS) -c WordMind.cpp

WordMind: $(OBJS)
	g++ $(FLAGS) -o WordMind $(OBJS)

# Clean target
clean:
	rm -f *.o WordMind

.PHONY: clean
