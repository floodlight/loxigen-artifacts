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

class OFOxmTcpFlagsMaskedVer15 implements OFOxmTcpFlagsMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmTcpFlagsMaskedVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 6;

        private final static U16 DEFAULT_VALUE = U16.ZERO;
        private final static U16 DEFAULT_VALUE_MASK = U16.ZERO;

    // OF message fields
    private final U16 value;
    private final U16 mask;
//
    // Immutable default instance
    final static OFOxmTcpFlagsMaskedVer15 DEFAULT = new OFOxmTcpFlagsMaskedVer15(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmTcpFlagsMaskedVer15(U16 value, U16 mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmTcpFlagsMaskedVer15: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmTcpFlagsMaskedVer15: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public U16 getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x80005504L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    public OFOxm<U16> getCanonical() {
        if (U16.NO_MASK.equals(mask)) {
            return new OFOxmTcpFlagsVer15(value);
        } else if(U16.FULL_MASK.equals(mask)) {
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
    public MatchField<U16> getMatchField() {
        return MatchField.TCP_FLAGS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmTcpFlagsMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmTcpFlagsMasked.Builder {
        final OFOxmTcpFlagsMaskedVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U16 value;
        private boolean maskSet;
        private U16 mask;

        BuilderWithParent(OFOxmTcpFlagsMaskedVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public U16 getMask() {
        return mask;
    }

    @Override
    public OFOxmTcpFlagsMasked.Builder setMask(U16 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80005504L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    @Override
    public OFOxmTcpFlagsMasked.Builder setValue(U16 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U16> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.TCP_FLAGS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmTcpFlagsMasked build() {
                U16 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                U16 mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmTcpFlagsMaskedVer15(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmTcpFlagsMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private U16 value;
        private boolean maskSet;
        private U16 mask;

    @Override
    public U16 getMask() {
        return mask;
    }

    @Override
    public OFOxmTcpFlagsMasked.Builder setMask(U16 mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80005504L;
    }

    @Override
    public U16 getValue() {
        return value;
    }

    @Override
    public OFOxmTcpFlagsMasked.Builder setValue(U16 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<U16> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<U16> getMatchField() {
        return MatchField.TCP_FLAGS;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmTcpFlagsMasked build() {
            U16 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            U16 mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmTcpFlagsMaskedVer15(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmTcpFlagsMasked> {
        @Override
        public OFOxmTcpFlagsMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80005504L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80005504)
                throw new OFParseError("Wrong typeLen: Expected=0x80005504L(0x80005504L), got="+typeLen);
            U16 value = U16.of(bb.readShort());
            U16 mask = U16.of(bb.readShort());

            OFOxmTcpFlagsMaskedVer15 oxmTcpFlagsMaskedVer15 = new OFOxmTcpFlagsMaskedVer15(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmTcpFlagsMaskedVer15);
            return oxmTcpFlagsMaskedVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmTcpFlagsMaskedVer15Funnel FUNNEL = new OFOxmTcpFlagsMaskedVer15Funnel();
    static class OFOxmTcpFlagsMaskedVer15Funnel implements Funnel<OFOxmTcpFlagsMaskedVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmTcpFlagsMaskedVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80005504L
            sink.putInt((int) 0x80005504);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmTcpFlagsMaskedVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmTcpFlagsMaskedVer15 message) {
            // fixed value property typeLen = 0x80005504L
            bb.writeInt((int) 0x80005504);
            bb.writeShort(message.value.getRaw());
            bb.writeShort(message.mask.getRaw());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmTcpFlagsMaskedVer15(");
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
        OFOxmTcpFlagsMaskedVer15 other = (OFOxmTcpFlagsMaskedVer15) obj;

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
