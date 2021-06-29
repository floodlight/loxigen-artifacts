// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_set_serializer.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

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
import org.projectfloodlight.openflow.protocol.OFBsnMiscCapabilities;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import java.util.EnumSet;
import java.util.Collections;


public class OFBsnMiscCapabilitiesSerializerVer15 {

    public final static long BSN_MISC_CAP_FEC_VAL = 0x1L;
    public final static long BSN_MISC_CAP_FEC_FIRE_CODE_VAL = 0x2L;
    public final static long BSN_MISC_CAP_FEC_REED_SOLOMAN_VAL = 0x4L;
    public final static long BSN_MISC_CAP_FEC_REED_SOLOMAN544_VAL = 0x8L;

    public static Set<OFBsnMiscCapabilities> readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readLong());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, Set<OFBsnMiscCapabilities> set) {
        bb.writeLong(toWireValue(set));
    }

    public static void putTo(Set<OFBsnMiscCapabilities> set, PrimitiveSink sink) {
        sink.putLong(toWireValue(set));
    }


    public static Set<OFBsnMiscCapabilities> ofWireValue(long val) {
        EnumSet<OFBsnMiscCapabilities> set = EnumSet.noneOf(OFBsnMiscCapabilities.class);

        if((val & BSN_MISC_CAP_FEC_VAL) != 0)
            set.add(OFBsnMiscCapabilities.BSN_MISC_CAP_FEC);
        if((val & BSN_MISC_CAP_FEC_FIRE_CODE_VAL) != 0)
            set.add(OFBsnMiscCapabilities.BSN_MISC_CAP_FEC_FIRE_CODE);
        if((val & BSN_MISC_CAP_FEC_REED_SOLOMAN_VAL) != 0)
            set.add(OFBsnMiscCapabilities.BSN_MISC_CAP_FEC_REED_SOLOMAN);
        if((val & BSN_MISC_CAP_FEC_REED_SOLOMAN544_VAL) != 0)
            set.add(OFBsnMiscCapabilities.BSN_MISC_CAP_FEC_REED_SOLOMAN544);
        return Collections.unmodifiableSet(set);
    }

    public static long toWireValue(Set<OFBsnMiscCapabilities> set) {
        long wireValue = 0;

        for(OFBsnMiscCapabilities e: set) {
            switch(e) {
                case BSN_MISC_CAP_FEC:
                    wireValue |= BSN_MISC_CAP_FEC_VAL;
                    break;
                case BSN_MISC_CAP_FEC_FIRE_CODE:
                    wireValue |= BSN_MISC_CAP_FEC_FIRE_CODE_VAL;
                    break;
                case BSN_MISC_CAP_FEC_REED_SOLOMAN:
                    wireValue |= BSN_MISC_CAP_FEC_REED_SOLOMAN_VAL;
                    break;
                case BSN_MISC_CAP_FEC_REED_SOLOMAN544:
                    wireValue |= BSN_MISC_CAP_FEC_REED_SOLOMAN544_VAL;
                    break;
                default:
                    throw new IllegalArgumentException("Illegal enum value for type OFBsnMiscCapabilities in version 1.5: " + e);
            }
        }
        return wireValue;
    }

}
