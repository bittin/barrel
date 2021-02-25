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


#ifndef BARREL_CREATE_RAID_H
#define BARREL_CREATE_RAID_H


#include "handle.h"


namespace barrel
{

    /**
     * The RAID level must be included in get_opts.
     */
    shared_ptr<Cmd>
    parse_create_raid(GetOpts& get_opts);

    /**
     * The RAID level must not be included in get_opts.
     */
    shared_ptr<Cmd>
    parse_create_raid0(GetOpts& get_opts);

    shared_ptr<Cmd>
    parse_create_raid1(GetOpts& get_opts);

    shared_ptr<Cmd>
    parse_create_raid4(GetOpts& get_opts);

    shared_ptr<Cmd>
    parse_create_raid5(GetOpts& get_opts);

    shared_ptr<Cmd>
    parse_create_raid6(GetOpts& get_opts);

    shared_ptr<Cmd>
    parse_create_raid10(GetOpts& get_opts);

}


#endif
