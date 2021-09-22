#include "COMMAND_PROCESS.h"

void COMMAND_PROCESS::Over_state(int way) {
	over.Overwrite(memory.get_Field_state(), way);
}
void COMMAND_PROCESS::Over_state1(int way) {
	over.Overwrite1(memory.get_Field_state(), memory.get_x(), memory.get_y(), memory.get_direct(), way);
}
void COMMAND_PROCESS::new_state(int way) {
	create.inArray(memory.get_Field_state());
	create.Arrayfull(memory.get_Field_state(), 0);
	create.inArray(memory.get_Field_result());
	create.Arrayfull(memory.get_Field_result(), 1);
	Over_state(way);
	cout << endl;
	output.prop(memory.get_x(), memory.get_y(), memory.get_direct(), memory.get_markers(), memory.get_Field_state());
}
void COMMAND_PROCESS::Commands(int n, int* h) {
	switch (n) {
	case 1:
		cout << "Command is executed to the left." << endl;
		left.To_the_left(memory.get_direct());
		break;

	case 2:
		cout << "Command is executed to the right." << endl;
		right.To_the_right(memory.get_direct());
		break;
	case 11:
		cout << "Command is executed step forward." << endl;
		move.Move(memory.get_x(), memory.get_y(), memory.get_direct(), memory.get_Field_state());
		break;
	case 21:
		cout << "Command is executed to take the marker." << endl;
		take.Take_marker(memory.get_x(), memory.get_y(), memory.get_markers(), memory.get_Field_state());
		//create.Overwrite(memory.get_Field_state());
		break;
	case 22:
		cout << "Command is executedto put the marker." << endl;
		put.Put_marker(memory.get_x(), memory.get_y(), memory.get_markers(), memory.get_Field_state());
		//create.Overwrite(memory.get_Field_state());
		break;
	case 31:
		cout << "Command is executed to test." << endl;
		test.Test(memory.get_Field_state(), memory.get_Field_result(), h);
		break;
	default:
		cout << "Unknown command." << endl;
	}
	output.prop(memory.get_x(), memory.get_y(), memory.get_direct(), memory.get_markers(), memory.get_Field_state());
}
void COMMAND_PROCESS::del_state() {
	create.Out_Array(memory.get_Field_state());
	create.DestructorArray(memory.get_Field_state());
	create.DestructorArray(memory.get_Field_result());
}
