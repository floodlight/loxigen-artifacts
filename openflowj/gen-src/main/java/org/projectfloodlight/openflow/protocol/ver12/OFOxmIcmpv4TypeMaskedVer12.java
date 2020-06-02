// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

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

class OFOxmIcmpv4TypeMaskedVer12 implements OFOxmIcmpv4TypeMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmIcmpv4TypeMaskedVer12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 6;

        private final static ICMPv4Type DEFAULT_VALUE = ICMPv4Type.NONE;
        private final static ICMPv4Type DEFAULT_VALUE_MASK = ICMPv4Type.NONE;

    // OF message fields
    private final ICMPv4Type value;
    private final ICMPv4Type mask;
//
    // Immutable default instance
    final static OFOxmIcmpv4TypeMaskedVer12 DEFAULT = new OFOxmIcmpv4TypeMaskedVer12(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmIcmpv4TypeMaskedVer12(ICMPv4Type value, ICMPv4Type mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmIcmpv4TypeMaskedVer12: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmIcmpv4TypeMaskedVer12: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public ICMPv4Type getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x80002702L;
    }

    @Override
    public ICMPv4Type getValue() {
        return value;
    }

    public OFOxm<ICMPv4Type> getCanonical() {
        if (ICMPv4Type.NO_MASK.equals(mask)) {
            return new OFOxmIcmpv4TypeVer12(value);
        } else if(ICMPv4Type.FULL_MASK.equals(mask)) {
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
    public MatchField<ICMPv4Type> getMatchField() {
        return MatchField.ICMPV4_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFOxmIcmpv4TypeMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmIcmpv4TypeMasked.Builder {
        final OFOxmIcmpv4TypeMaskedVer12 parentMessage;

        // OF message fields
        private boolean valueSet;
        private ICMPv4Type value;
        private boolean maskSet;
        private ICMPv4Type mask;

        BuilderWithParent(OFOxmIcmpv4TypeMaskedVer12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public ICMPv4Type getMask() {
        return mask;
    }

    @Override
    public OFOxmIcmpv4TypeMasked.Builder setMask(ICMPv4Type mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80002702L;
    }

    @Override
    public ICMPv4Type getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv4TypeMasked.Builder setValue(ICMPv4Type value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ICMPv4Type> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<ICMPv4Type> getMatchField() {
        return MatchField.ICMPV4_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFOxmIcmpv4TypeMasked build() {
                ICMPv4Type value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                ICMPv4Type mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmIcmpv4TypeMaskedVer12(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmIcmpv4TypeMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private ICMPv4Type value;
        private boolean maskSet;
        private ICMPv4Type mask;

    @Override
    public ICMPv4Type getMask() {
        return mask;
    }

    @Override
    public OFOxmIcmpv4TypeMasked.Builder setMask(ICMPv4Type mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80002702L;
    }

    @Override
    public ICMPv4Type getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv4TypeMasked.Builder setValue(ICMPv4Type value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<ICMPv4Type> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<ICMPv4Type> getMatchField() {
        return MatchField.ICMPV4_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFOxmIcmpv4TypeMasked build() {
            ICMPv4Type value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            ICMPv4Type mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmIcmpv4TypeMaskedVer12(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmIcmpv4TypeMasked> {
        @Override
        public OFOxmIcmpv4TypeMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80002702L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80002702)
                throw new OFParseError("Wrong typeLen: Expected=0x80002702L(0x80002702L), got="+typeLen);
            ICMPv4Type value = ICMPv4Type.readByte(bb);
            ICMPv4Type mask = ICMPv4Type.readByte(bb);

            OFOxmIcmpv4TypeMaskedVer12 oxmIcmpv4TypeMaskedVer12 = new OFOxmIcmpv4TypeMaskedVer12(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmIcmpv4TypeMaskedVer12);
            return oxmIcmpv4TypeMaskedVer12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmIcmpv4TypeMaskedVer12Funnel FUNNEL = new OFOxmIcmpv4TypeMaskedVer12Funnel();
    static class OFOxmIcmpv4TypeMaskedVer12Funnel implements Funnel<OFOxmIcmpv4TypeMaskedVer12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmIcmpv4TypeMaskedVer12 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80002702L
            sink.putInt((int) 0x80002702);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmIcmpv4TypeMaskedVer12> {
        @Override
        public void write(ByteBuf bb, OFOxmIcmpv4TypeMaskedVer12 message) {
            // fixed value property typeLen = 0x80002702L
            bb.writeInt((int) 0x80002702);
            message.value.writeByte(bb);
            message.mask.writeByte(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmIcmpv4TypeMaskedVer12(");
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
        OFOxmIcmpv4TypeMaskedVer12 other = (OFOxmIcmpv4TypeMaskedVer12) obj;

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
