//***************************************************************************
// File name:  TextUIWidget.h
// Author:     Chadd Williams
// Date:       3/39/2017
// Class:      CS485
// Assignment: TextUI
// Purpose:    Provide event based TextUI
//***************************************************************************
#pragma once
#include <string>

class ITextUIWidget
{
public:

  virtual ~ITextUIWidget () = default;
	virtual void setData(std::string data) {mData = data;	};
	virtual std::string getData() const {return mData;	};

	virtual void setLabel(std::string label) {mLabel = label;};
	virtual std::string getLabel() const { return mLabel; };
	virtual void draw(std::ostream&) const = 0;

  virtual int getLength () const = 0;
  virtual bool isVisible () const { return mbVisible; };

  virtual void setVisible (bool bVis) { mbVisible = bVis; };

private:
	std::string mData;
	std::string mLabel;
  bool mbVisible = true;
};
