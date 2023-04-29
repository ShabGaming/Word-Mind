display_word.o : display_word.cpp display_word.h
	g++ display_word.cpp -c display_word.o

edit_load_profile.o : edit_load_profile.cpp edit_load_profile.h
	g++ edit_load_profile -c edit_load_profile.o

generate_extract_file.o : generate_extract_file.cpp generate_extract_file.h
	g++ generate_extract_file.cpp -c generate_extract_file.o

generate_hint_validate.o : generate_hint_validate.cpp generate_hint_validate.h
	g++ generate_hint_validate.cpp -c generate_hint_validate.o

introductions_into_leaderboard.o: introductions_into_leaderboard.cpp introductions_into_leaderboard.h
	g++ introductions_into_leaderboard.cpp -c introductions_into_leaderboard.o

WordMind: introductions_into_leaderboard.o display_word.o edit_load_profile.o generate_extract_file.o generate_hint_validate.o
	g++ $^ -o $@

clean:
	rm -f *.o WordMind

.PHONY: clean
