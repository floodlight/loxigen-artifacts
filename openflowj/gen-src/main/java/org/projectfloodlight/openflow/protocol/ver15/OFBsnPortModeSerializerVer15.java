// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_serializer.java
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
import org.projectfloodlight.openflow.protocol.OFBsnPortMode;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;

public class OFBsnPortModeSerializerVer15 {

    public final static short BSN_PORT_MODE_NONE_VAL = (short) 0x0;
    public final static short BSN_PORT_MODE_4XX_VAL = (short) 0x1;
    public final static short BSN_PORT_MODE_4X1_VAL = (short) 0x2;
    public final static short BSN_PORT_MODE_4X10_VAL = (short) 0x3;
    public final static short BSN_PORT_MODE_4X25_VAL = (short) 0x4;
    public final static short BSN_PORT_MODE_2X50_VAL = (short) 0x5;
    public final static short BSN_PORT_MODE_1X1_VAL = (short) 0x6;
    public final static short BSN_PORT_MODE_1X10_VAL = (short) 0x7;
    public final static short BSN_PORT_MODE_1X25_VAL = (short) 0x8;
    public final static short BSN_PORT_MODE_1X40_VAL = (short) 0x9;
    public final static short BSN_PORT_MODE_1X100_VAL = (short) 0xa;
    public final static short BSN_PORT_MODE_8X25_VAL = (short) 0xb;
    public final static short BSN_PORT_MODE_8X50_VAL = (short) 0xc;
    public final static short BSN_PORT_MODE_4X50_VAL = (short) 0xd;
    public final static short BSN_PORT_MODE_1X50_VAL = (short) 0xe;
    public final static short BSN_PORT_MODE_1X200_VAL = (short) 0xf;
    public final static short BSN_PORT_MODE_1X400_VAL = (short) 0x10;

    public static OFBsnPortMode readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readShort());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, OFBsnPortMode e) {
        bb.writeShort(toWireValue(e));
    }

    public static void putTo(OFBsnPortMode e, PrimitiveSink sink) {
        sink.putShort(toWireValue(e));
    }

    public static OFBsnPortMode ofWireValue(short val) {
        switch(val) {
            case BSN_PORT_MODE_NONE_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_NONE;
            case BSN_PORT_MODE_4XX_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_4XX;
            case BSN_PORT_MODE_4X1_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_4X1;
            case BSN_PORT_MODE_4X10_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_4X10;
            case BSN_PORT_MODE_4X25_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_4X25;
            case BSN_PORT_MODE_2X50_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_2X50;
            case BSN_PORT_MODE_1X1_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X1;
            case BSN_PORT_MODE_1X10_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X10;
            case BSN_PORT_MODE_1X25_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X25;
            case BSN_PORT_MODE_1X40_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X40;
            case BSN_PORT_MODE_1X100_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X100;
            case BSN_PORT_MODE_8X25_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_8X25;
            case BSN_PORT_MODE_8X50_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_8X50;
            case BSN_PORT_MODE_4X50_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_4X50;
            case BSN_PORT_MODE_1X50_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X50;
            case BSN_PORT_MODE_1X200_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X200;
            case BSN_PORT_MODE_1X400_VAL:
                return OFBsnPortMode.BSN_PORT_MODE_1X400;
            default:
                throw new IllegalArgumentException("Illegal wire value for type OFBsnPortMode in version 1.5: " + val);
        }
    }


    public static short toWireValue(OFBsnPortMode e) {
        switch(e) {
            case BSN_PORT_MODE_NONE:
                return BSN_PORT_MODE_NONE_VAL;
            case BSN_PORT_MODE_4XX:
                return BSN_PORT_MODE_4XX_VAL;
            case BSN_PORT_MODE_4X1:
                return BSN_PORT_MODE_4X1_VAL;
            case BSN_PORT_MODE_4X10:
                return BSN_PORT_MODE_4X10_VAL;
            case BSN_PORT_MODE_4X25:
                return BSN_PORT_MODE_4X25_VAL;
            case BSN_PORT_MODE_2X50:
                return BSN_PORT_MODE_2X50_VAL;
            case BSN_PORT_MODE_1X1:
                return BSN_PORT_MODE_1X1_VAL;
            case BSN_PORT_MODE_1X10:
                return BSN_PORT_MODE_1X10_VAL;
            case BSN_PORT_MODE_1X25:
                return BSN_PORT_MODE_1X25_VAL;
            case BSN_PORT_MODE_1X40:
                return BSN_PORT_MODE_1X40_VAL;
            case BSN_PORT_MODE_1X100:
                return BSN_PORT_MODE_1X100_VAL;
            case BSN_PORT_MODE_8X25:
                return BSN_PORT_MODE_8X25_VAL;
            case BSN_PORT_MODE_8X50:
                return BSN_PORT_MODE_8X50_VAL;
            case BSN_PORT_MODE_4X50:
                return BSN_PORT_MODE_4X50_VAL;
            case BSN_PORT_MODE_1X50:
                return BSN_PORT_MODE_1X50_VAL;
            case BSN_PORT_MODE_1X200:
                return BSN_PORT_MODE_1X200_VAL;
            case BSN_PORT_MODE_1X400:
                return BSN_PORT_MODE_1X400_VAL;
            default:
                throw new IllegalArgumentException("Illegal enum value for type OFBsnPortMode in version 1.5: " + e);
        }
    }

}
