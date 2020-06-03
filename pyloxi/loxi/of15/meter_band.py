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
ofp = sys.modules['loxi.of15']

class meter_band(loxi.OFObject):
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
        subclass = meter_band.subtypes.get(subtype)
        if subclass:
            return subclass.unpack(reader)

        obj = meter_band()
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
        q.text("meter_band {")
        with q.group():
            with q.indent(2):
                q.breakable()
            q.breakable()
        q.text('}')


class drop(meter_band):
    type = 1

    def __init__(self, rate=None, burst_size=None):
        if rate != None:
            self.rate = rate
        else:
            self.rate = 0
        if burst_size != None:
            self.burst_size = burst_size
        else:
            self.burst_size = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.rate))
        packed.append(struct.pack("!L", self.burst_size))
        packed.append('\x00' * 4)
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = drop()
        _type = reader.read("!H")[0]
        assert(_type == 1)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        obj.rate = reader.read("!L")[0]
        obj.burst_size = reader.read("!L")[0]
        reader.skip(4)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.rate != other.rate: return False
        if self.burst_size != other.burst_size: return False
        return True

    def pretty_print(self, q):
        q.text("drop {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("rate = ");
                q.text("%#x" % self.rate)
                q.text(","); q.breakable()
                q.text("burst_size = ");
                q.text("%#x" % self.burst_size)
            q.breakable()
        q.text('}')

meter_band.subtypes[1] = drop

class dscp_remark(meter_band):
    type = 2

    def __init__(self, rate=None, burst_size=None, prec_level=None):
        if rate != None:
            self.rate = rate
        else:
            self.rate = 0
        if burst_size != None:
            self.burst_size = burst_size
        else:
            self.burst_size = 0
        if prec_level != None:
            self.prec_level = prec_level
        else:
            self.prec_level = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.rate))
        packed.append(struct.pack("!L", self.burst_size))
        packed.append(struct.pack("!B", self.prec_level))
        packed.append('\x00' * 3)
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = dscp_remark()
        _type = reader.read("!H")[0]
        assert(_type == 2)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        obj.rate = reader.read("!L")[0]
        obj.burst_size = reader.read("!L")[0]
        obj.prec_level = reader.read("!B")[0]
        reader.skip(3)
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.rate != other.rate: return False
        if self.burst_size != other.burst_size: return False
        if self.prec_level != other.prec_level: return False
        return True

    def pretty_print(self, q):
        q.text("dscp_remark {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("rate = ");
                q.text("%#x" % self.rate)
                q.text(","); q.breakable()
                q.text("burst_size = ");
                q.text("%#x" % self.burst_size)
                q.text(","); q.breakable()
                q.text("prec_level = ");
                q.text("%#x" % self.prec_level)
            q.breakable()
        q.text('}')

meter_band.subtypes[2] = dscp_remark

class experimenter(meter_band):
    type = 65535

    def __init__(self, rate=None, burst_size=None, experimenter=None):
        if rate != None:
            self.rate = rate
        else:
            self.rate = 0
        if burst_size != None:
            self.burst_size = burst_size
        else:
            self.burst_size = 0
        if experimenter != None:
            self.experimenter = experimenter
        else:
            self.experimenter = 0
        return

    def pack(self):
        packed = []
        packed.append(struct.pack("!H", self.type))
        packed.append(struct.pack("!H", 0)) # placeholder for len at index 1
        packed.append(struct.pack("!L", self.rate))
        packed.append(struct.pack("!L", self.burst_size))
        packed.append(struct.pack("!L", self.experimenter))
        length = sum([len(x) for x in packed])
        packed[1] = struct.pack("!H", length)
        return ''.join(packed)

    @staticmethod
    def unpack(reader):
        obj = experimenter()
        _type = reader.read("!H")[0]
        assert(_type == 65535)
        _len = reader.read("!H")[0]
        orig_reader = reader
        reader = orig_reader.slice(_len, 4)
        obj.rate = reader.read("!L")[0]
        obj.burst_size = reader.read("!L")[0]
        obj.experimenter = reader.read("!L")[0]
        return obj

    def __eq__(self, other):
        if type(self) != type(other): return False
        if self.rate != other.rate: return False
        if self.burst_size != other.burst_size: return False
        if self.experimenter != other.experimenter: return False
        return True

    def pretty_print(self, q):
        q.text("experimenter {")
        with q.group():
            with q.indent(2):
                q.breakable()
                q.text("rate = ");
                q.text("%#x" % self.rate)
                q.text(","); q.breakable()
                q.text("burst_size = ");
                q.text("%#x" % self.burst_size)
                q.text(","); q.breakable()
                q.text("experimenter = ");
                q.text("%#x" % self.experimenter)
            q.breakable()
        q.text('}')

meter_band.subtypes[65535] = experimenter


