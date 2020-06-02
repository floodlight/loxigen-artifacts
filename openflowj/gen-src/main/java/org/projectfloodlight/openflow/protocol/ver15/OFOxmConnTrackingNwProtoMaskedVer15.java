// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmConnTrackingNwProtoMaskedVer15 implements OFOxmConnTrackingNwProtoMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmConnTrackingNwProtoMaskedVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 6;

        private final static U8 DEFAULT_VALUE = U8.ZERO;
        private final static U8 DEFAULT_VALUE_MASK = U8.ZERO;

    // OF message fields
    private final U8 value;
    private final U8 mask;
//
    // Immutable default instance
    final static OFOxmConnTrackingNwProtoMaskedVer15 DEFAULT = new OFOxmConnTrackingNwProtoMaskedVer15(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmConnTrackingNwProtoMaskedVer15(U8 value, U8 mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmConnTrackingNwProtoMaskedVer15: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmConnTrackingNwProtoMaskedVer15: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public U8 getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x1ef02L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    public OFOxm<U8> getCanonical() {
        if (U8.NO_MASK.equals(mask)) {
            return new OFOxmConnTrackingNwProtoVer15(value);
        } else if(U8.FULL_MASK.equals(mask)) {
            return null;
        } else {
            return this;
        }
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.CONN_TRACKING_NW_PROTO;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmConnTrackingNwProtoMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmConnTrackingNwProtoMasked.Builder {
        final OFOxmConnTrackingNwProtoMaskedVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U8 value;
        private boolean maskSet;
        private U8 mask;

        BuilderWithParent(OFOxmConnTrackingNwProtoMaskedVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public U8 getMask() {
        return mask;
    }

    @Override
    public OFOxmConnTrackingNwProtoMasked.Builder setMask(U8 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x1ef02L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    @Override
    public OFOxmConnTrackingNwProtoMasked.Builder setValue(U8 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U8> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.CONN_TRACKING_NW_PROTO;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmConnTrackingNwProtoMasked build() {
                U8 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                U8 mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmConnTrackingNwProtoMaskedVer15(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmConnTrackingNwProtoMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private U8 value;
        private boolean maskSet;
        private U8 mask;

    @Override
    public U8 getMask() {
        return mask;
    }

    @Override
    public OFOxmConnTrackingNwProtoMasked.Builder setMask(U8 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x1ef02L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    @Override
    public OFOxmConnTrackingNwProtoMasked.Builder setValue(U8 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U8> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.CONN_TRACKING_NW_PROTO;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmConnTrackingNwProtoMasked build() {
            U8 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            U8 mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmConnTrackingNwProtoMaskedVer15(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmConnTrackingNwProtoMasked> {
        @Override
        public OFOxmConnTrackingNwProtoMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x1ef02L
            int typeLen = bb.readInt();
            if(typeLen != 0x1ef02)
                throw new OFParseError("Wrong typeLen: Expected=0x1ef02L(0x1ef02L), got="+typeLen);
            U8 value = U8.of(bb.readByte());
            U8 mask = U8.of(bb.readByte());

            OFOxmConnTrackingNwProtoMaskedVer15 oxmConnTrackingNwProtoMaskedVer15 = new OFOxmConnTrackingNwProtoMaskedVer15(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmConnTrackingNwProtoMaskedVer15);
            return oxmConnTrackingNwProtoMaskedVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmConnTrackingNwProtoMaskedVer15Funnel FUNNEL = new OFOxmConnTrackingNwProtoMaskedVer15Funnel();
    static class OFOxmConnTrackingNwProtoMaskedVer15Funnel implements Funnel<OFOxmConnTrackingNwProtoMaskedVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmConnTrackingNwProtoMaskedVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x1ef02L
            sink.putInt(0x1ef02);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmConnTrackingNwProtoMaskedVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmConnTrackingNwProtoMaskedVer15 message) {
            // fixed value property typeLen = 0x1ef02L
            bb.writeInt(0x1ef02);
            bb.writeByte(message.value.getRaw());
            bb.writeByte(message.mask.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmConnTrackingNwProtoMaskedVer15(");
        b.append("value=").append(value);
        b.append(", ");
        b.append("mask=").append(mask);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmConnTrackingNwProtoMaskedVer15 other = (OFOxmConnTrackingNwProtoMaskedVer15) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        if (mask == null) {
            if (other.mask != null)
                return false;
        } else if (!mask.equals(other.mask))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        result = prime * result + ((mask == null) ? 0 : mask.hashCode());
        return result;
    }

}
