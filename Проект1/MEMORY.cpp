#include "MEMORY.h"

int MEMORY::get_Commands() {
	k++;
	return Commands[k];
}
int* MEMORY::get_x() {
	return &x;
}
int* MEMORY::get_y() {
	return &y;
}
int* MEMORY::get_direct() {
	return &direct;
}
int* MEMORY::get_markers() {
	return &markers;
}
int** MEMORY::get_Field_state() {
	return Field_state;
}
int** MEMORY::get_Field_result() {
	return Field_result;
}
