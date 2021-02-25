/*
 * Copyright (c) 2021 SUSE LLC
 *
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, contact SUSE LLC.
 *
 * To contact SUSE LLC about this file by physical or electronic mail, you may
 * find current contact information at www.suse.com.
 */


#include <stdexcept>

#include <storage/Utils/HumanString.h>

#include "Misc.h"
#include "Text.h"


namespace barrel
{

    using namespace std;
    using namespace storage;


    string
    format_size(unsigned long long size)
    {
	return byte_to_humanstring(size, false, 2, false);
    }


    string
    format_percentage(unsigned long long a, unsigned long long b)
    {
	if (b == 0)
	    return "";

	return sformat("%.2f%%", 100.0 * (double)(a) / (double)(b));
    }


    SmartSize::SmartSize(const string& str)
    {
	if (str == "max")
	{
	    type = MAX;
	}
	else
	{
	    type = ABSOLUTE;

	    absolute = humanstring_to_byte(str, false);
	}
    }


    unsigned long long
    SmartSize::value(unsigned long long max) const
    {
	switch (type)
	{
	    case SmartSize::MAX:
		return max;

	    case SmartSize::ABSOLUTE:
		return absolute;

	    default:
		throw runtime_error("unknown SmartSize type");
	}
    }

}
