# Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
# Copyright (c) 2011, 2012 Open Networking Foundation
# Copyright (c) 2012, 2013 Big Switch Networks, Inc.
# See the file LICENSE.pyloxi which should have been included in the source distribution

# Automatically generated by LOXI from template module.py
# Do not modify

import struct
import loxi
from . import util
import functools
import loxi.generic_util

import sys
ofp = sys.modules['loxi.of14']

class instruction_id(loxi.OFObject):
    subtypes = {}


    def __init__(self, type=None):
        if type != None:
            self.type = type
        else:
            self.type = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        subtype, = reader.peek('!H', 0)
        subclass = instruction_id.subtypes.get(subtype)
        if subclass:
            return subclass.unpack(reader)

        obj = instruction_id()
        obj.type = reader.read("!H")[0]
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.type != other.type: return False
        return True

    def pretty_print(self, q):
        q.text("instruction_id {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')


class apply_actions(instruction_id):
    type = 4

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = apply_actions()
        _type = reader.read("!H")[0]
        assert(_type == 4)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("apply_actions {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[4] = apply_actions

class experimenter(instruction_id):
    subtypes = {}

    type = 65535

    def __init__(self, experimenter=None):
        if experimenter != None:
            self.experimenter = experimenter
        else:
            self.experimenter = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        subtype, = reader.peek('!L', 4)
        subclass = experimenter.subtypes.get(subtype)
        if subclass:
            return subclass.unpack(reader)

        obj = experimenter()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        obj.experimenter = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.experimenter != other.experimenter: return False
        return True

    def pretty_print(self, q):
        q.text("experimenter {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[65535] = experimenter

class bsn(experimenter):
    subtypes = {}

    type = 65535
    experimenter = 6035143

    def __init__(self, subtype=None):
        if subtype != None:
            self.subtype = subtype
        else:
            self.subtype = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        subtype, = reader.peek('!L', 8)
        subclass = bsn.subtypes.get(subtype)
        if subclass:
            return subclass.unpack(reader)

        obj = bsn()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        obj.subtype = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.subtype != other.subtype: return False
        return True

    def pretty_print(self, q):
        q.text("bsn {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

experimenter.subtypes[6035143] = bsn

class bsn_arp_offload(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 1

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_arp_offload()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 1)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_arp_offload {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[1] = bsn_arp_offload

class bsn_auto_negotiation(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 11

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_auto_negotiation()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 11)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_auto_negotiation {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[11] = bsn_auto_negotiation

class bsn_deny(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 5

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_deny()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 5)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_deny {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[5] = bsn_deny

class bsn_dhcp_offload(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 2

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_dhcp_offload()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 2)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_dhcp_offload {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[2] = bsn_dhcp_offload

class bsn_directed_broadcast(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 16

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_directed_broadcast()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 16)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_directed_broadcast {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[16] = bsn_directed_broadcast

class bsn_disable_l3(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 13

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_disable_l3()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 13)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_disable_l3 {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[13] = bsn_disable_l3

class bsn_disable_src_mac_check(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 0

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_disable_src_mac_check()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 0)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_disable_src_mac_check {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[0] = bsn_disable_src_mac_check

class bsn_disable_vlan_counters(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 9

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_disable_vlan_counters()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 9)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_disable_vlan_counters {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[9] = bsn_disable_vlan_counters

class bsn_hash_select(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 15

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_hash_select()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 15)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_hash_select {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[15] = bsn_hash_select

class bsn_internal_priority(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 12

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_internal_priority()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 12)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_internal_priority {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[12] = bsn_internal_priority

class bsn_ndp_offload(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 14

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_ndp_offload()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 14)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_ndp_offload {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[14] = bsn_ndp_offload

class bsn_packet_of_death(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 6

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_packet_of_death()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 6)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_packet_of_death {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[6] = bsn_packet_of_death

class bsn_permit(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 4

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_permit()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_permit {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[4] = bsn_permit

class bsn_prioritize_pdus(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 7

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_prioritize_pdus()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 7)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_prioritize_pdus {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[7] = bsn_prioritize_pdus

class bsn_require_vlan_xlate(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 8

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_require_vlan_xlate()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 8)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_require_vlan_xlate {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[8] = bsn_require_vlan_xlate

class bsn_span_destination(bsn):
    type = 65535
    experimenter = 6035143
    subtype = 10

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.experimenter))
        packed.append(struct.pack("!L", self.subtype))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = bsn_span_destination()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        _experimenter = reader.read("!L")[0]
        assert(_experimenter == 6035143)
        _subtype = reader.read("!L")[0]
        assert(_subtype == 10)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("bsn_span_destination {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

bsn.subtypes[10] = bsn_span_destination

class clear_actions(instruction_id):
    type = 5

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = clear_actions()
        _type = reader.read("!H")[0]
        assert(_type == 5)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("clear_actions {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[5] = clear_actions

class goto_table(instruction_id):
    type = 1

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = goto_table()
        _type = reader.read("!H")[0]
        assert(_type == 1)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("goto_table {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[1] = goto_table

class meter(instruction_id):
    type = 6

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = meter()
        _type = reader.read("!H")[0]
        assert(_type == 6)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("meter {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[6] = meter

class write_actions(instruction_id):
    type = 3

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = write_actions()
        _type = reader.read("!H")[0]
        assert(_type == 3)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("write_actions {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[3] = write_actions

class write_metadata(instruction_id):
    type = 2

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = write_metadata()
        _type = reader.read("!H")[0]
        assert(_type == 2)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("write_metadata {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

instruction_id.subtypes[2] = write_metadata


