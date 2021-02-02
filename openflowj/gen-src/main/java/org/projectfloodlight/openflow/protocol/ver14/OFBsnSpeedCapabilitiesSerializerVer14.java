// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_set_serializer.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver14;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.projectfloodlight.openflow.protocol.OFBsnSpeedCapabilities;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import java.util.EnumSet;
import java.util.Collections;


public class OFBsnSpeedCapabilitiesSerializerVer14 {

    public final static long BSN_SPEED_CAP_10M_VAL = 0x1L;
    public final static long BSN_SPEED_CAP_100M_VAL = 0x2L;
    public final static long BSN_SPEED_CAP_1GB_VAL = 0x4L;
    public final static long BSN_SPEED_CAP_10GB_VAL = 0x8L;
    public final static long BSN_SPEED_CAP_25GB_VAL = 0x10L;
    public final static long BSN_SPEED_CAP_40GB_VAL = 0x20L;
    public final static long BSN_SPEED_CAP_50GB_VAL = 0x40L;
    public final static long BSN_SPEED_CAP_100GB_VAL = 0x80L;
    public final static long BSN_SPEED_CAP_200GB_VAL = 0x100L;
    public final static long BSN_SPEED_CAP_400GB_VAL = 0x200L;

    public static Set<OFBsnSpeedCapabilities> readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readLong());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, Set<OFBsnSpeedCapabilities> set) {
        bb.writeLong(toWireValue(set));
    }

    public static void putTo(Set<OFBsnSpeedCapabilities> set, PrimitiveSink sink) {
        sink.putLong(toWireValue(set));
    }


    public static Set<OFBsnSpeedCapabilities> ofWireValue(long val) {
        EnumSet<OFBsnSpeedCapabilities> set = EnumSet.noneOf(OFBsnSpeedCapabilities.class);

        if((val & BSN_SPEED_CAP_10M_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_10M);
        if((val & BSN_SPEED_CAP_100M_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_100M);
        if((val & BSN_SPEED_CAP_1GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_1GB);
        if((val & BSN_SPEED_CAP_10GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_10GB);
        if((val & BSN_SPEED_CAP_25GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_25GB);
        if((val & BSN_SPEED_CAP_40GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_40GB);
        if((val & BSN_SPEED_CAP_50GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_50GB);
        if((val & BSN_SPEED_CAP_100GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_100GB);
        if((val & BSN_SPEED_CAP_200GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_200GB);
        if((val & BSN_SPEED_CAP_400GB_VAL) != 0)
            set.add(OFBsnSpeedCapabilities.BSN_SPEED_CAP_400GB);
        return Collections.unmodifiableSet(set);
    }

    public static long toWireValue(Set<OFBsnSpeedCapabilities> set) {
        long wireValue = 0;

        for(OFBsnSpeedCapabilities e: set) {
            switch(e) {
                case BSN_SPEED_CAP_10M:
                    wireValue |= BSN_SPEED_CAP_10M_VAL;
                    break;
                case BSN_SPEED_CAP_100M:
                    wireValue |= BSN_SPEED_CAP_100M_VAL;
                    break;
                case BSN_SPEED_CAP_1GB:
                    wireValue |= BSN_SPEED_CAP_1GB_VAL;
                    break;
                case BSN_SPEED_CAP_10GB:
                    wireValue |= BSN_SPEED_CAP_10GB_VAL;
                    break;
                case BSN_SPEED_CAP_25GB:
                    wireValue |= BSN_SPEED_CAP_25GB_VAL;
                    break;
                case BSN_SPEED_CAP_40GB:
                    wireValue |= BSN_SPEED_CAP_40GB_VAL;
                    break;
                case BSN_SPEED_CAP_50GB:
                    wireValue |= BSN_SPEED_CAP_50GB_VAL;
                    break;
                case BSN_SPEED_CAP_100GB:
                    wireValue |= BSN_SPEED_CAP_100GB_VAL;
                    break;
                case BSN_SPEED_CAP_200GB:
                    wireValue |= BSN_SPEED_CAP_200GB_VAL;
                    break;
                case BSN_SPEED_CAP_400GB:
                    wireValue |= BSN_SPEED_CAP_400GB_VAL;
                    break;
                default:
                    throw new IllegalArgumentException("Illegal enum value for type OFBsnSpeedCapabilities in version 1.4: " + e);
            }
        }
        return wireValue;
    }

}
