// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmIcmpv6TypeMaskedVer14 implements OFOxmIcmpv6TypeMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmIcmpv6TypeMaskedVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 6;

        private final static U8 DEFAULT_VALUE = U8.ZERO;
        private final static U8 DEFAULT_VALUE_MASK = U8.ZERO;

    // OF message fields
    private final U8 value;
    private final U8 mask;
//
    // Immutable default instance
    final static OFOxmIcmpv6TypeMaskedVer14 DEFAULT = new OFOxmIcmpv6TypeMaskedVer14(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmIcmpv6TypeMaskedVer14(U8 value, U8 mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmIcmpv6TypeMaskedVer14: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmIcmpv6TypeMaskedVer14: property mask cannot be null");
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
        return 0x80003b02L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    public OFOxm<U8> getCanonical() {
        if (U8.NO_MASK.equals(mask)) {
            return new OFOxmIcmpv6TypeVer14(value);
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
        return MatchField.ICMPV6_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFOxmIcmpv6TypeMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmIcmpv6TypeMasked.Builder {
        final OFOxmIcmpv6TypeMaskedVer14 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U8 value;
        private boolean maskSet;
        private U8 mask;

        BuilderWithParent(OFOxmIcmpv6TypeMaskedVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public U8 getMask() {
        return mask;
    }

    @Override
    public OFOxmIcmpv6TypeMasked.Builder setMask(U8 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80003b02L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv6TypeMasked.Builder setValue(U8 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U8> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.ICMPV6_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFOxmIcmpv6TypeMasked build() {
                U8 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                U8 mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmIcmpv6TypeMaskedVer14(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmIcmpv6TypeMasked.Builder {
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
    public OFOxmIcmpv6TypeMasked.Builder setMask(U8 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80003b02L;
    }

    @Override
    public U8 getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv6TypeMasked.Builder setValue(U8 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U8> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U8> getMatchField() {
        return MatchField.ICMPV6_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFOxmIcmpv6TypeMasked build() {
            U8 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            U8 mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmIcmpv6TypeMaskedVer14(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmIcmpv6TypeMasked> {
        @Override
        public OFOxmIcmpv6TypeMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80003b02L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80003b02)
                throw new OFParseError("Wrong typeLen: Expected=0x80003b02L(0x80003b02L), got="+typeLen);
            U8 value = U8.of(bb.readByte());
            U8 mask = U8.of(bb.readByte());

            OFOxmIcmpv6TypeMaskedVer14 oxmIcmpv6TypeMaskedVer14 = new OFOxmIcmpv6TypeMaskedVer14(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmIcmpv6TypeMaskedVer14);
            return oxmIcmpv6TypeMaskedVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmIcmpv6TypeMaskedVer14Funnel FUNNEL = new OFOxmIcmpv6TypeMaskedVer14Funnel();
    static class OFOxmIcmpv6TypeMaskedVer14Funnel implements Funnel<OFOxmIcmpv6TypeMaskedVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmIcmpv6TypeMaskedVer14 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80003b02L
            sink.putInt((int) 0x80003b02);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmIcmpv6TypeMaskedVer14> {
        @Override
        public void write(ByteBuf bb, OFOxmIcmpv6TypeMaskedVer14 message) {
            // fixed value property typeLen = 0x80003b02L
            bb.writeInt((int) 0x80003b02);
            bb.writeByte(message.value.getRaw());
            bb.writeByte(message.mask.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmIcmpv6TypeMaskedVer14(");
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
        OFOxmIcmpv6TypeMaskedVer14 other = (OFOxmIcmpv6TypeMaskedVer14) obj;

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
