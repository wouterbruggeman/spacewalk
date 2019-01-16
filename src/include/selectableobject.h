#ifndef SELECTABLEOBJECT_H
#define SELECTABLEOBJECT_H

class SelectableObject{
	public:
		SelectableObject(int color, int colorSelected);

		//Make the class abstract,
		//but inheriting classes do not need to implement the function
		virtual ~SelectableObject() = 0;

		int getColor(bool selected);
		void setSelected(bool state);
		bool getSelected();

	private:
		int _color;
		int _colorSelected;

		bool _selected;
};
#endif
