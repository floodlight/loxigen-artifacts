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

class OFOxmEthTypeVer13 implements OFOxmEthType {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmEthTypeVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 6;

        private final static EthType DEFAULT_VALUE = EthType.NONE;

    // OF message fields
    private final EthType value;
//
    // Immutable default instance
    final static OFOxmEthTypeVer13 DEFAULT = new OFOxmEthTypeVer13(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmEthTypeVer13(EthType value) {
        if(value == null) {
            throw new NullPointerException("OFOxmEthTypeVer13: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80000a02L;
    }

    @Override
    public EthType getValue() {
        return value;
    }

    public OFOxm<EthType> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public EthType getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<EthType> getMatchField() {
        return MatchField.ETH_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFOxmEthType.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmEthType.Builder {
        final OFOxmEthTypeVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private EthType value;

        BuilderWithParent(OFOxmEthTypeVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80000a02L;
    }

    @Override
    public EthType getValue() {
        return value;
    }

    @Override
    public OFOxmEthType.Builder setValue(EthType value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<EthType> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public EthType getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<EthType> getMatchField() {
        return MatchField.ETH_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFOxmEthType build() {
                EthType value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmEthTypeVer13(
                    value
                );
        }

    }

    static class Builder implements OFOxmEthType.Builder {
        // OF message fields
        private boolean valueSet;
        private EthType value;

    @Override
    public long getTypeLen() {
        return 0x80000a02L;
    }

    @Override
    public EthType getValue() {
        return value;
    }

    @Override
    public OFOxmEthType.Builder setValue(EthType value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFOxm<EthType> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public EthType getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.3");
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public MatchField<EthType> getMatchField() {
        return MatchField.ETH_TYPE;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFOxmEthType build() {
            EthType value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmEthTypeVer13(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmEthType> {
        @Override
        public OFOxmEthType readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80000a02L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80000a02)
                throw new OFParseError("Wrong typeLen: Expected=0x80000a02L(0x80000a02L), got="+typeLen);
            EthType value = EthType.read2Bytes(bb);

            OFOxmEthTypeVer13 oxmEthTypeVer13 = new OFOxmEthTypeVer13(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmEthTypeVer13);
            return oxmEthTypeVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmEthTypeVer13Funnel FUNNEL = new OFOxmEthTypeVer13Funnel();
    static class OFOxmEthTypeVer13Funnel implements Funnel<OFOxmEthTypeVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmEthTypeVer13 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80000a02L
            sink.putInt((int) 0x80000a02);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmEthTypeVer13> {
        @Override
        public void write(ByteBuf bb, OFOxmEthTypeVer13 message) {
            // fixed value property typeLen = 0x80000a02L
            bb.writeInt((int) 0x80000a02);
            message.value.write2Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmEthTypeVer13(");
        b.append("value=").append(value);
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
        OFOxmEthTypeVer13 other = (OFOxmEthTypeVer13) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}
