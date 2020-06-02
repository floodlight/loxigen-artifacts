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

class OFOxmEthTypeMaskedVer15 implements OFOxmEthTypeMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmEthTypeMaskedVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 8;

        private final static EthType DEFAULT_VALUE = EthType.NONE;
        private final static EthType DEFAULT_VALUE_MASK = EthType.NONE;

    // OF message fields
    private final EthType value;
    private final EthType mask;
//
    // Immutable default instance
    final static OFOxmEthTypeMaskedVer15 DEFAULT = new OFOxmEthTypeMaskedVer15(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmEthTypeMaskedVer15(EthType value, EthType mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmEthTypeMaskedVer15: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmEthTypeMaskedVer15: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public EthType getMask() {
        return mask;
    }

    @Override
    public long getTypeLen() {
        return 0x80000b04L;
    }

    @Override
    public EthType getValue() {
        return value;
    }

    public OFOxm<EthType> getCanonical() {
        if (EthType.NO_MASK.equals(mask)) {
            return new OFOxmEthTypeVer15(value);
        } else if(EthType.FULL_MASK.equals(mask)) {
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
    public MatchField<EthType> getMatchField() {
        return MatchField.ETH_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFOxmEthTypeMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmEthTypeMasked.Builder {
        final OFOxmEthTypeMaskedVer15 parentMessage;

        // OF message fields
        private boolean valueSet;
        private EthType value;
        private boolean maskSet;
        private EthType mask;

        BuilderWithParent(OFOxmEthTypeMaskedVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public EthType getMask() {
        return mask;
    }

    @Override
    public OFOxmEthTypeMasked.Builder setMask(EthType mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80000b04L;
    }

    @Override
    public EthType getValue() {
        return value;
    }

    @Override
    public OFOxmEthTypeMasked.Builder setValue(EthType value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<EthType> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<EthType> getMatchField() {
        return MatchField.ETH_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFOxmEthTypeMasked build() {
                EthType value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                EthType mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmEthTypeMaskedVer15(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmEthTypeMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private EthType value;
        private boolean maskSet;
        private EthType mask;

    @Override
    public EthType getMask() {
        return mask;
    }

    @Override
    public OFOxmEthTypeMasked.Builder setMask(EthType mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public long getTypeLen() {
        return 0x80000b04L;
    }

    @Override
    public EthType getValue() {
        return value;
    }

    @Override
    public OFOxmEthTypeMasked.Builder setValue(EthType value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<EthType> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.5");
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public MatchField<EthType> getMatchField() {
        return MatchField.ETH_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFOxmEthTypeMasked build() {
            EthType value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            EthType mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmEthTypeMaskedVer15(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmEthTypeMasked> {
        @Override
        public OFOxmEthTypeMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80000b04L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80000b04)
                throw new OFParseError("Wrong typeLen: Expected=0x80000b04L(0x80000b04L), got="+typeLen);
            EthType value = EthType.read2Bytes(bb);
            EthType mask = EthType.read2Bytes(bb);

            OFOxmEthTypeMaskedVer15 oxmEthTypeMaskedVer15 = new OFOxmEthTypeMaskedVer15(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmEthTypeMaskedVer15);
            return oxmEthTypeMaskedVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmEthTypeMaskedVer15Funnel FUNNEL = new OFOxmEthTypeMaskedVer15Funnel();
    static class OFOxmEthTypeMaskedVer15Funnel implements Funnel<OFOxmEthTypeMaskedVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmEthTypeMaskedVer15 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80000b04L
            sink.putInt((int) 0x80000b04);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmEthTypeMaskedVer15> {
        @Override
        public void write(ByteBuf bb, OFOxmEthTypeMaskedVer15 message) {
            // fixed value property typeLen = 0x80000b04L
            bb.writeInt((int) 0x80000b04);
            message.value.write2Bytes(bb);
            message.mask.write2Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmEthTypeMaskedVer15(");
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
        OFOxmEthTypeMaskedVer15 other = (OFOxmEthTypeMaskedVer15) obj;

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
