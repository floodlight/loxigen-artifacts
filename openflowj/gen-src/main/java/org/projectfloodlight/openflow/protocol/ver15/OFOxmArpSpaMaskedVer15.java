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

class OFOxmArpSpaMaskedVer15 implements OFOxmArpSpaMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmArpSpaMaskedVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 12;

        private final static IPv4Address DEFAULT_VALUE = IPv4Address.NONE;
        private final static IPv4Address DEFAULT_VALUE_MASK = IPv4Address.NONE;

    // OF message fields
    private final IPv4Address value;
    private final IPv4Address mask;
//
    // Immutable default instance
    final static OFOxmArpSpaMaskedVer15 DEFAULT = new OFOxmArpSpaMaskedVer15(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmArpSpaMaskedVer15(IPv4Address value, IPv4Address mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmArpSpaMaskedVer15: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmArpSpaMaskedVer15: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public IPv4Address getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x80002d08L;
    }

    @Override
    public IPv4Address getValue() {
        return value;
    }

    public OFOxm<IPv4Address> getCanonical() {
        if (IPv4Address.NO_MASK.equals(mask)) {
            return new OFOxmArpSpaVer15(value);
        } else if(IPv4Address.FULL_MASK.equals(mask)) {
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
    public MatchField<IPv4Address> getMatchField() {
        return MatchField.ARP_SPA;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmArpSpaMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmArpSpaMasked.Builder {
        final OFOxmArpSpaMaskedVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private IPv4Address value;
        private boolean maskSet;
        private IPv4Address mask;

        BuilderWithParent(OFOxmArpSpaMaskedVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public IPv4Address getMask() {
        return mask;
    }

    @Override
    public OFOxmArpSpaMasked.Builder setMask(IPv4Address mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80002d08L;
    }

    @Override
    public IPv4Address getValue() {
        return value;
    }

    @Override
    public OFOxmArpSpaMasked.Builder setValue(IPv4Address value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<IPv4Address> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<IPv4Address> getMatchField() {
        return MatchField.ARP_SPA;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmArpSpaMasked build() {
                IPv4Address value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                IPv4Address mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmArpSpaMaskedVer15(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmArpSpaMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private IPv4Address value;
        private boolean maskSet;
        private IPv4Address mask;

    @Override
    public IPv4Address getMask() {
        return mask;
    }

    @Override
    public OFOxmArpSpaMasked.Builder setMask(IPv4Address mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80002d08L;
    }

    @Override
    public IPv4Address getValue() {
        return value;
    }

    @Override
    public OFOxmArpSpaMasked.Builder setValue(IPv4Address value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<IPv4Address> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<IPv4Address> getMatchField() {
        return MatchField.ARP_SPA;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmArpSpaMasked build() {
            IPv4Address value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            IPv4Address mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmArpSpaMaskedVer15(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmArpSpaMasked> {
        @Override
        public OFOxmArpSpaMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80002d08L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80002d08)
                throw new OFParseError("Wrong typeLen: Expected=0x80002d08L(0x80002d08L), got="+typeLen);
            IPv4Address value = IPv4Address.read4Bytes(bb);
            IPv4Address mask = IPv4Address.read4Bytes(bb);

            OFOxmArpSpaMaskedVer15 oxmArpSpaMaskedVer15 = new OFOxmArpSpaMaskedVer15(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmArpSpaMaskedVer15);
            return oxmArpSpaMaskedVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmArpSpaMaskedVer15Funnel FUNNEL = new OFOxmArpSpaMaskedVer15Funnel();
    static class OFOxmArpSpaMaskedVer15Funnel implements Funnel<OFOxmArpSpaMaskedVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmArpSpaMaskedVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80002d08L
            sink.putInt((int) 0x80002d08);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmArpSpaMaskedVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmArpSpaMaskedVer15 message) {
            // fixed value property typeLen = 0x80002d08L
            bb.writeInt((int) 0x80002d08);
            message.value.write4Bytes(bb);
            message.mask.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmArpSpaMaskedVer15(");
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
        OFOxmArpSpaMaskedVer15 other = (OFOxmArpSpaMaskedVer15) obj;

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
