#include <iostream>
#include <fstream>
#include <cstring>


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "invalid paramers" << std::endl;
		return 0;
	}

	int delta = atoi(argv[1]);

	int max_level = 7;
	int cur_level = 3;

	std::string path = "/sys/class/backlight/backlight";

	std::ifstream ifs_max(path + "/max_brightness");
	ifs_max >> max_level;
	ifs_max.close();

	std::ifstream ifs_cur(path + "/actual_brightness");
	ifs_cur >> cur_level;
	ifs_cur.close();


	int new_level = cur_level+delta;
	if (new_level < 0)
		new_level = 0;

	if (new_level > max_level)
		new_level = max_level;

	char buf[15];
	sprintf(&buf[0], "%d", new_level);

	std::ofstream ofs_set(path + "/brightness");
	ofs_set.write(&buf[0], strlen(buf));
	ofs_set.close();

	return 0;
}
