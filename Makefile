display_word.o : display_word.cpp display_word.h
	g++ display_word.cpp -c display_word.o

edit_load_profile.o : edit_load_profile.cpp edit_load_profile.h
	g++ edit_load_profile -c edit_load_profile.o

generate_extract_file.o : generate_extract_file.cpp generate_extract_file.h
	g++ generate_extract_file.cpp -c generate_extract_file.o

generate_hint_validate.o : generate_hint_validate.cpp generate_hint_validate.h
	g++ generate_hint_validate.cpp -c generate_hint_validate.o

instructions_intro_leaderboard.o: instructions_intro_leaderboard.cpp instructions_intro_leaderboard.h
	g++ instructions_intro_leaderboard.cpp -c instructions_intro_leaderboard.o

WordMind: instructions_intro_leaderboard.o display_word.o edit_load_profile.o generate_extract_file.o generate_hint_validate.o
	g++ $^ -o $@

clean:
	rm -f *.o WordMind

.PHONY: clean
