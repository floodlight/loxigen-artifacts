// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

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

class OFOxmIpv6SrcMaskedVer13 implements OFOxmIpv6SrcMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmIpv6SrcMaskedVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 36;

        private final static IPv6Address DEFAULT_VALUE = IPv6Address.NONE;
        private final static IPv6Address DEFAULT_VALUE_MASK = IPv6Address.NONE;

    // OF message fields
    private final IPv6Address value;
    private final IPv6Address mask;
//
    // Immutable default instance
    final static OFOxmIpv6SrcMaskedVer13 DEFAULT = new OFOxmIpv6SrcMaskedVer13(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmIpv6SrcMaskedVer13(IPv6Address value, IPv6Address mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmIpv6SrcMaskedVer13: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmIpv6SrcMaskedVer13: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80003520L;
    }

    @Override
    public IPv6Address getValue() {
        return value;
    }

    @Override
    public IPv6Address getMask() {
        return mask;
    }

    @Override
    public MatchField<IPv6Address> getMatchField() {
        return MatchField.IPV6_SRC;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    public OFOxm<IPv6Address> getCanonical() {
        if (IPv6Address.NO_MASK.equals(mask)) {
            return new OFOxmIpv6SrcVer13(value);
        } else if(IPv6Address.FULL_MASK.equals(mask)) {
            return null;
        } else {
            return this;
        }
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFOxmIpv6SrcMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmIpv6SrcMasked.Builder {
        final OFOxmIpv6SrcMaskedVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private IPv6Address value;
        private boolean maskSet;
        private IPv6Address mask;

        BuilderWithParent(OFOxmIpv6SrcMaskedVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80003520L;
    }

    @Override
    public IPv6Address getValue() {
        return value;
    }

    @Override
    public OFOxmIpv6SrcMasked.Builder setValue(IPv6Address value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public IPv6Address getMask() {
        return mask;
    }

    @Override
    public OFOxmIpv6SrcMasked.Builder setMask(IPv6Address mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public MatchField<IPv6Address> getMatchField() {
        return MatchField.IPV6_SRC;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public OFOxm<IPv6Address> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFOxmIpv6SrcMasked build() {
                IPv6Address value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                IPv6Address mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmIpv6SrcMaskedVer13(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmIpv6SrcMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private IPv6Address value;
        private boolean maskSet;
        private IPv6Address mask;

    @Override
    public long getTypeLen() {
        return 0x80003520L;
    }

    @Override
    public IPv6Address getValue() {
        return value;
    }

    @Override
    public OFOxmIpv6SrcMasked.Builder setValue(IPv6Address value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public IPv6Address getMask() {
        return mask;
    }

    @Override
    public OFOxmIpv6SrcMasked.Builder setMask(IPv6Address mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public MatchField<IPv6Address> getMatchField() {
        return MatchField.IPV6_SRC;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public OFOxm<IPv6Address> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFOxmIpv6SrcMasked build() {
            IPv6Address value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            IPv6Address mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmIpv6SrcMaskedVer13(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader extends AbstractOFMessageReader<OFOxmIpv6SrcMasked> {
        @Override
        public OFOxmIpv6SrcMasked readFrom(OFMessageReaderContext context, ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < LENGTH)
                return null;
            // fixed value property typeLen == 0x80003520L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80003520)
                throw new OFParseError("Wrong typeLen: Expected=0x80003520L(0x80003520L), got="+typeLen);
            IPv6Address value = IPv6Address.read16Bytes(bb);
            IPv6Address mask = IPv6Address.read16Bytes(bb);

            OFOxmIpv6SrcMaskedVer13 oxmIpv6SrcMaskedVer13 = new OFOxmIpv6SrcMaskedVer13(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmIpv6SrcMaskedVer13);
            return oxmIpv6SrcMaskedVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmIpv6SrcMaskedVer13Funnel FUNNEL = new OFOxmIpv6SrcMaskedVer13Funnel();
    static class OFOxmIpv6SrcMaskedVer13Funnel implements Funnel<OFOxmIpv6SrcMaskedVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmIpv6SrcMaskedVer13 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80003520L
            sink.putInt((int) 0x80003520);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmIpv6SrcMaskedVer13> {
        @Override
        public void write(ByteBuf bb, OFOxmIpv6SrcMaskedVer13 message) {
            // fixed value property typeLen = 0x80003520L
            bb.writeInt((int) 0x80003520);
            message.value.write16Bytes(bb);
            message.mask.write16Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmIpv6SrcMaskedVer13(");
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
        OFOxmIpv6SrcMaskedVer13 other = (OFOxmIpv6SrcMaskedVer13) obj;

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
