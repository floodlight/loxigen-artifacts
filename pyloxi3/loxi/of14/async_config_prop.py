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

class async_config_prop(loxi.OFObject):
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
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        subtype, = reader.peek('!H', 0)
        subclass = async_config_prop.subtypes.get(subtype)
        if subclass:
            return subclass.unpack(reader)

        obj = async_config_prop()
        obj.type = reader.read("!H")[0]
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.type != other.type: return False
        return True

    def pretty_print(self, q):
        q.text("async_config_prop {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')


class experimenter_master(async_config_prop):
    type = 65535

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = experimenter_master()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("experimenter_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

async_config_prop.subtypes[65535] = experimenter_master

class experimenter_slave(async_config_prop):
    type = 65534

    def __init__(self):
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = experimenter_slave()
        _type = reader.read("!H")[0]
        assert(_type == 65534)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        return True

    def pretty_print(self, q):
        q.text("experimenter_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')

async_config_prop.subtypes[65534] = experimenter_slave

class flow_removed_master(async_config_prop):
    type = 5

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = flow_removed_master()
        _type = reader.read("!H")[0]
        assert(_type == 5)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("flow_removed_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[5] = flow_removed_master

class flow_removed_slave(async_config_prop):
    type = 4

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = flow_removed_slave()
        _type = reader.read("!H")[0]
        assert(_type == 4)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("flow_removed_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[4] = flow_removed_slave

class packet_in_master(async_config_prop):
    type = 1

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = packet_in_master()
        _type = reader.read("!H")[0]
        assert(_type == 1)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("packet_in_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[1] = packet_in_master

class packet_in_slave(async_config_prop):
    type = 0

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = packet_in_slave()
        _type = reader.read("!H")[0]
        assert(_type == 0)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("packet_in_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[0] = packet_in_slave

class port_status_master(async_config_prop):
    type = 3

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = port_status_master()
        _type = reader.read("!H")[0]
        assert(_type == 3)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("port_status_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[3] = port_status_master

class port_status_slave(async_config_prop):
    type = 2

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = port_status_slave()
        _type = reader.read("!H")[0]
        assert(_type == 2)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("port_status_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[2] = port_status_slave

class requestforward_master(async_config_prop):
    type = 11

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = requestforward_master()
        _type = reader.read("!H")[0]
        assert(_type == 11)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("requestforward_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[11] = requestforward_master

class requestforward_slave(async_config_prop):
    type = 10

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = requestforward_slave()
        _type = reader.read("!H")[0]
        assert(_type == 10)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("requestforward_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[10] = requestforward_slave

class role_status_master(async_config_prop):
    type = 7

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = role_status_master()
        _type = reader.read("!H")[0]
        assert(_type == 7)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("role_status_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[7] = role_status_master

class role_status_slave(async_config_prop):
    type = 6

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = role_status_slave()
        _type = reader.read("!H")[0]
        assert(_type == 6)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("role_status_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[6] = role_status_slave

class table_status_master(async_config_prop):
    type = 9

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = table_status_master()
        _type = reader.read("!H")[0]
        assert(_type == 9)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("table_status_master {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[9] = table_status_master

class table_status_slave(async_config_prop):
    type = 8

    def __init__(self, mask=None):
        if mask != None:
            self.mask = mask
        else:
            self.mask = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for length at index 1
        packed.append(struct.pack("!L", self.mask))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return functools.reduce(lambda x,y: x+y, packed)

    @staticmethod
    def unpack(reader):
        obj = table_status_slave()
        _type = reader.read("!H")[0]
        assert(_type == 8)
        _length = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_length, 4)
        obj.mask = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.mask != other.mask: return False
        return True

    def pretty_print(self, q):
        q.text("table_status_slave {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("mask = ");
                q.text("%#x" % self.mask)
            q.breakable()
        q.text('}')

async_config_prop.subtypes[8] = table_status_slave


